// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a ControlDict useful for the OpenFOAM snappyHexMesh utility
//******************************************************************************

#ifndef SNAPPYFILESWRITER_CONTROLDICT_WRITER_H
#define SNAPPYFILESWRITER_CONTROLDICT_WRITER_H

#include "fstream"

class ControlDict_Writer {

public:
    /**
     * @brief Write the ControlDict
     *
     * @param fileName_without_extension file name without extension
     * @return true if ControlDict is written, false otherwise
     */
    bool write_controlDict(std::string& fileName_without_extension);
};


#endif //SNAPPYFILESWRITER_CONTROLDICT_WRITER_H
