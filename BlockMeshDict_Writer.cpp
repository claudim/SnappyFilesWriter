#include "BlockMeshDict_Writer.h"

bool BlockMeshDict_Writer::write_blockMeshDict(std::string& inputSTLfileName, int resolution) {

//    size_t lastIndex  = inputSTLfileName.find_last_of(".");
//    std::string fileName = inputSTLfileName.substr(0,lastIndex);

    size_t startIndex  = inputSTLfileName.find_last_of("/");
    std::string fileName_with_extension = inputSTLfileName.substr(startIndex + 1,inputSTLfileName.size());
    std::string fileName_without_extension = fileName_with_extension.substr(0,(fileName_with_extension.size()-4));

    std::map<std::string, double> blockMesh_parameters;
    bool are_parameters_found = this->find_blockMesh_parameters(inputSTLfileName, blockMesh_parameters, resolution);
    if(are_parameters_found) {
        std::ofstream blockMeshDict_file;
        std::string path = "./snappyWD/"+ fileName_without_extension + "/system/blockMeshDict";
        blockMeshDict_file.open(path);
        if (blockMeshDict_file.is_open()) {
            blockMeshDict_file << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
            blockMeshDict_file << "  =========                 | \n";
            blockMeshDict_file << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
            blockMeshDict_file << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
            blockMeshDict_file << "    \\\\  /    A nd           | Version:  8 \n";
            blockMeshDict_file << "     \\\\/     M anipulation  | \n";
            blockMeshDict_file << " \\*---------------------------------------------------------------------------*/ \n";
            blockMeshDict_file << "FoamFile \n";
            blockMeshDict_file << "{ \n";
            blockMeshDict_file << "    version     2.0; \n";
            blockMeshDict_file << "    format      ascii; \n";
            blockMeshDict_file << "    class       dictionary; \n";
            blockMeshDict_file << "    location    \"system\"; \n";
            blockMeshDict_file << "    object      blockMeshDict; \n";
            blockMeshDict_file << "} \n";
            blockMeshDict_file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
            blockMeshDict_file << " \n";
            blockMeshDict_file << "convertToMeters 1;";
            blockMeshDict_file << " \n";
            blockMeshDict_file << "vertices \n";
            blockMeshDict_file << "( \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_min"] << " " << blockMesh_parameters["y_min"] << " "
                               << blockMesh_parameters["z_min"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_max"] << " " << blockMesh_parameters["y_min"] << " "
                               << blockMesh_parameters["z_min"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_max"] << " " << blockMesh_parameters["y_max"] << " "
                               << blockMesh_parameters["z_min"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_min"] << " " << blockMesh_parameters["y_max"] << " "
                               << blockMesh_parameters["z_min"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_min"] << " " << blockMesh_parameters["y_min"] << " "
                               << blockMesh_parameters["z_max"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_max"] << " " << blockMesh_parameters["y_min"] << " "
                               << blockMesh_parameters["z_max"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_max"] << " " << blockMesh_parameters["y_max"] << " "
                               << blockMesh_parameters["z_max"] << ") \n";
            blockMeshDict_file << "    ( " << blockMesh_parameters["x_min"] << " " << blockMesh_parameters["y_max"] << " "
                               << blockMesh_parameters["z_max"] << ") \n";
            blockMeshDict_file << "); \n";
            blockMeshDict_file << "\n";
            blockMeshDict_file << "blocks \n";
            blockMeshDict_file << "( \n";
            blockMeshDict_file << "    hex (0 1 2 3 4 5 6 7)  \n";
            blockMeshDict_file << "    (" << blockMesh_parameters["x_axis_cell_numb"] << " "
                               << blockMesh_parameters["y_axis_cell_numb"] << " "
                               << blockMesh_parameters["z_axis_cell_numb"]
                               << ") // number of cell to create in each axis direction \n";
            blockMeshDict_file << "    simpleGrading (1 1 1) //uniform mesh \n";
            blockMeshDict_file << ");\n";
            blockMeshDict_file << "\n";
            blockMeshDict_file << "edges \n";
            blockMeshDict_file << "( \n";
            blockMeshDict_file << "); \n";
            blockMeshDict_file << "\n";
            blockMeshDict_file << "boundary \n";
            blockMeshDict_file << "( \n";
            blockMeshDict_file << "); \n";
            blockMeshDict_file << "\n";
            blockMeshDict_file << "// ************************************************************************* //";
            blockMeshDict_file.close();
            return true;
        }
    }
    return false;
}

bool BlockMeshDict_Writer::find_blockMesh_parameters(std::string& inputSTLfileName, std::map<std::string, double>& blockMesh_parameters, int resolution)
{
    STL_reader reader;
    const Polyhedron polyhedron = reader.read(inputSTLfileName);

    //int resolution = 8;
    //int resolution = 24;

    double grid_dimension;

    typedef CGAL::Bbox_3 Bbox;
    Bbox grid_box;

    const CGAL::Bbox_3 &polyhedron_bbox3 = CGAL::Polygon_mesh_processing::bbox(polyhedron);

    double delta_x = polyhedron_bbox3.xmax() - polyhedron_bbox3.xmin();
    double delta_y = polyhedron_bbox3.ymax() - polyhedron_bbox3.ymin();
    double delta_z = polyhedron_bbox3.zmax() - polyhedron_bbox3.zmin();

    grid_dimension = std::min(std::min(delta_y, delta_z), delta_x) / resolution;

    grid_box = CGAL::Bbox_3(polyhedron_bbox3.xmin() - grid_dimension,
                            polyhedron_bbox3.ymin() - grid_dimension,
                            polyhedron_bbox3.zmin() - grid_dimension,
                            polyhedron_bbox3.xmax() + grid_dimension,
                            polyhedron_bbox3.ymax() + grid_dimension,
                            polyhedron_bbox3.zmax() + grid_dimension);
    double delta_x_grid = grid_box.xmax() - grid_box.xmin();
    double delta_y_grid = grid_box.ymax() - grid_box.ymin();
    double delta_z_grid = grid_box.zmax() - grid_box.zmin();

    double x_dimension = delta_x_grid;
    double y_dimension = delta_y_grid;
    double z_dimension = delta_z_grid;

    this->_polyhedron_internal_point = Point(grid_box.xmin() + x_dimension / 2,
                          grid_box.ymin() + y_dimension / 2,
                          grid_box.zmin() + z_dimension / 2);

    CGAL::Vertex_location_finder vertexLocationFinder = CGAL::Vertex_location_finder(polyhedron);
    while(!vertexLocationFinder.is_point_inside_polyhedron(this->_polyhedron_internal_point))
    {
        double x_rand = this->fRand(polyhedron_bbox3.xmin(), polyhedron_bbox3.xmax());
        double y_rand = this->fRand(polyhedron_bbox3.ymin(), polyhedron_bbox3.ymax());
        double z_rand = this->fRand(polyhedron_bbox3.zmin(), polyhedron_bbox3.zmax());
        this->_polyhedron_internal_point = Point(x_rand, y_rand, z_rand);
    }



    double number_of_x_nodes = round(x_dimension / grid_dimension);
    double number_of_y_nodes = round(y_dimension / grid_dimension);
    double number_of_z_nodes = round(z_dimension / grid_dimension);

    blockMesh_parameters["x_min"] = polyhedron_bbox3.xmin();
    blockMesh_parameters["y_min"] = polyhedron_bbox3.ymin();
    blockMesh_parameters["z_min"] = polyhedron_bbox3.zmin();
    blockMesh_parameters["x_max"] = polyhedron_bbox3.xmax();
    blockMesh_parameters["y_max"] = polyhedron_bbox3.ymax();
    blockMesh_parameters["z_max"] = polyhedron_bbox3.zmax();
    blockMesh_parameters["x_axis_cell_numb"] = number_of_x_nodes;
    blockMesh_parameters["y_axis_cell_numb"] = number_of_y_nodes;
    blockMesh_parameters["z_axis_cell_numb"] = number_of_z_nodes;

    return true;
}

Point BlockMeshDict_Writer::getPolyhedronInternalPoint() const {
    return _polyhedron_internal_point;
}

double BlockMeshDict_Writer::fRand(double fMin, double fMax)
{
//    double f = (double)rand() / RAND_MAX;
//    return fMin + f * (fMax - fMin);

//Type of random number distribution
    std::uniform_real_distribution<double> dist(fMin, fMax);  //(min, max)

    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng;
    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}());

    return dist(rng);

}



