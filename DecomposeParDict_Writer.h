// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a decomposeParDict useful for the OpenFOAM utilities
//******************************************************************************

#ifndef SNAPPYFILESWRITER_DECOMPOSEPARDICT_WRITER_H
#define SNAPPYFILESWRITER_DECOMPOSEPARDICT_WRITER_H

#include "fstream"

class DecomposeParDict_Writer {
public:
    /**
     * @brief Write the decomposeParDict
     *
     * @param fileName_without_extension file name without extension
     * @return true if decomposeParDict is written, false otherwise
     */
    bool write_decomposeParDict(std::string& fileName_without_extension);

};


#endif //SNAPPYFILESWRITER_DECOMPOSEPARDICT_WRITER_H
