
#ifndef SNAPPYFILESWRITER_VERTEX_LOCATION_FINDER_H
#define SNAPPYFILESWRITER_VERTEX_LOCATION_FINDER_H


#include <CGAL/Polyhedral_mesh_domain_with_features_3.h>
#include <CGAL/Linear_cell_complex_for_combinatorial_map.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/AABB_tree.h>
#include <CGAL/AABB_traits.h>
#include <CGAL/AABB_face_graph_triangle_primitive.h>
#include <CGAL/Side_of_triangle_mesh.h>
#include <MyLCC.h>


//typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Mesh_polyhedron_3<K>::type Polyhedron;
typedef CGAL::Side_of_triangle_mesh<Polyhedron, K> Point_inside;
//typedef CGAL::Linear_cell_complex_for_combinatorial_map<3> LCC_3;
//typedef LCC_3::Point Point;
//typedef LCC_3::Dart_handle Dart_handle;
typedef CGAL::AABB_face_graph_triangle_primitive<Polyhedron> Primitive;
typedef CGAL::AABB_traits<K, Primitive> AABB_Traits;
typedef CGAL::AABB_tree<AABB_Traits> Tree;
//typedef LCC_3::FT FT;

namespace CGAL {
    class Vertex_location_finder {
    protected:
        Polyhedron polyhedron;
        Point_inside inside;
        Tree AABB_tree;
        int point_internal_check_tolerance = 0; // distance_tolerance between the point_to_check and the boundary surface

    public:

        Vertex_location_finder(const Polyhedron &polyhedron)
                : inside(polyhedron), AABB_tree(faces(polyhedron).first, faces(polyhedron).second, polyhedron) {
            this->polyhedron = polyhedron;
            AABB_tree.accelerate_distance_queries();
        }

        //template<typename Point>
        bool is_point_inside_polyhedron(const Point &pointToBeCheck);

        bool is_point_onBoundary_polyhedron(const Point &pointToBeCheck) const;

        bool is_point_external_polyhedron(const Point &pointToBeCheck);
        

        const Tree &getAabbTree();


        // template<typename Point>
        //bool is_point_too_close_to_the_boundary(const Point &point);
        bool is_point_too_close_to_the_boundary(const Point &point, const FT &distance);
    };

}


#endif //SNAPPYFILESWRITER_VERTEX_LOCATION_FINDER_H
