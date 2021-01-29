// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a meshQualityDict useful for the OpenFOAM utilities
//******************************************************************************


#ifndef SNAPPYFILESWRITER_MESHQUALITYDICT_WRITER_H
#define SNAPPYFILESWRITER_MESHQUALITYDICT_WRITER_H

#include "fstream"

class MeshQualityDict_Writer {
public:
    /**
     * @brief Write the meshQualityDict
     *
     * @param fileName_without_extension file name without extension
     * @return true if meshQualityDict is written, false otherwise
     */
    bool write_meshQualityDict(std::string& fileName_without_extension);

};


#endif //SNAPPYFILESWRITER_MESHQUALITYDICT_WRITER_H
