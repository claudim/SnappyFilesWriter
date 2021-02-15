// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a blockMeshDict useful for the OpenFOAM BlockMeshDict utility
//******************************************************************************


#ifndef SNAPPYFILESWRITER_BLOCKMESHDICT_WRITER_H
#define SNAPPYFILESWRITER_BLOCKMESHDICT_WRITER_H

#include "fstream"
#include "STL_Reader.h"
#include "CGAL/Polygon_mesh_processing/bbox.h"
#include "Vertex_location_finder.h"
#include <random>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Point_3<K>                                    Point;


class BlockMeshDict_Writer {

private:
    Point _polyhedron_internal_point;
    //int _precision = 4;
    //int _precision = 3;
    int _precision = 2;

    double fRand(double fMin, double fMax);
public:

    Point getPolyhedronInternalPoint() const;

    /**
     * @brief Write the blockMeshDict
     *
     * @return true if blockMeshDict is written, false otherwise
     */
    bool write_blockMeshDict(std::string& inputSTLfileName, int resolution);

    bool find_blockMesh_parameters(std::string& inputSTLfileName, std::map<std::string, double>& blockMesh_parameters, int resolution);

    /**
     * @brief Set the precision of digits numbers.
     *
     * @param precision The precision of decimal numbers.
     */
    void setPrecision(int precision) {
        _precision = precision;
    }

};

#endif //SNAPPYFILESWRITER_BLOCKMESHDICT_WRITER_H
