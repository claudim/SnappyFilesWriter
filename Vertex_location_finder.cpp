#include "Vertex_location_finder.h"

#include "Vertex_location_finder.h"

const Tree &CGAL::Vertex_location_finder::getAabbTree(){
    return this->AABB_tree;
}

//template<typename Point>
bool CGAL::Vertex_location_finder::is_point_inside_polyhedron(const Point &pointToBeCheck) {
    bool isInternalPoint = false;
    // Point_inside inside(polyhedron);
    if (inside(pointToBeCheck) == CGAL::ON_BOUNDED_SIDE){
        isInternalPoint = true;
    }
    if (this->point_internal_check_tolerance > 0 && inside(pointToBeCheck) != CGAL::ON_BOUNDED_SIDE ){
        isInternalPoint= true;
        FT squareDistance = AABB_tree.squared_distance(pointToBeCheck);
        if(squareDistance > std::pow(this->point_internal_check_tolerance, 2))
        {
            isInternalPoint = false;
        }
    }
    return isInternalPoint;
}

bool CGAL::Vertex_location_finder::is_point_onBoundary_polyhedron(const Point &pointToBeCheck) const {
    bool isOnBoundaryPoint = false;
    //Point_inside inside(polyhedron);
    if (inside(pointToBeCheck) == CGAL::ON_BOUNDARY){
        isOnBoundaryPoint = true;
    }
    if(this->point_internal_check_tolerance > 0 && inside(pointToBeCheck) == CGAL::ON_UNBOUNDED_SIDE) //if point is external but is outside of about a minimal distance
    {
        //int tolerance = 0.001;
        int tolerance = this->point_internal_check_tolerance;
        isOnBoundaryPoint = true;
        FT squareDistance = AABB_tree.squared_distance(pointToBeCheck);
        if(squareDistance > std::pow(tolerance, 2))
        {
            isOnBoundaryPoint = false;
        }
    }
    return isOnBoundaryPoint;
}

bool CGAL::Vertex_location_finder::is_point_external_polyhedron(const Point &pointToBeCheck) {
    bool isExternalPoint = false;
    //Point_inside inside(polyhedron);
    if (inside(pointToBeCheck) == CGAL::ON_UNBOUNDED_SIDE){
        FT squareDistance = AABB_tree.squared_distance(pointToBeCheck);
        if(squareDistance > 0)
        {
            isExternalPoint = true;
        }
    }
    return isExternalPoint;
}


//template<typename Point>
bool CGAL::Vertex_location_finder::is_point_too_close_to_the_boundary(const Point &point, const FT &distance) {
    bool tooClose = false;
    FT squareDistance = AABB_tree.squared_distance(point);
    if(squareDistance < distance)
    {
        tooClose = true;
    }
    return tooClose;
}


