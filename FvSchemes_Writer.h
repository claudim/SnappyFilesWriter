// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a fvSchemes useful for the OpenFOAM utilities
//******************************************************************************


#ifndef SNAPPYFILESWRITER_FVSCHEMES_WRITER_H
#define SNAPPYFILESWRITER_FVSCHEMES_WRITER_H

#include "fstream"

class FvSchemes_Writer {
public:
    /**
     * @brief Write the fvSchemes
     *
     * @param fileName_without_extension file name without extension
     * @return true if fvSchemes is written, false otherwise
     */
    bool write_fvSchemes(std::string& fileName_without_extension);

};


#endif //SNAPPYFILESWRITER_FVSCHEMES_WRITER_H
