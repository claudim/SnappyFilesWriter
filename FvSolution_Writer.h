// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a fvSolution useful for the OpenFOAM utilities
//******************************************************************************

#ifndef SNAPPYFILESWRITER_FVSOLUTION_WRITER_H
#define SNAPPYFILESWRITER_FVSOLUTION_WRITER_H

#include "fstream"

class FvSolution_Writer {
public:
    /**
     * @brief Write the fvSolution
     *
     * @param fileName_without_extension file name without extension
     * @return true if fvSolution is written, false otherwise
     */
    bool write_fvSolution(std::string& fileName_without_extension);

};


#endif //SNAPPYFILESWRITER_FVSOLUTION_WRITER_H
