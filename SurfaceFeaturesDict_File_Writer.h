// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a SurfaceFeaturesDict useful for the OpenFOAM surfaceFeatureExtract utility
//******************************************************************************


#ifndef SNAPPYFILESWRITER_SURFACEFEATURESDICT_FILE_WRITER_H
#define SNAPPYFILESWRITER_SURFACEFEATURESDICT_FILE_WRITER_H

#include "fstream"

class SurfaceFeaturesDict_File_Writer {
public:
    /**
     * @brief Write a SurfaceFeaturesDict useful for the OpenFOAM surfaceFeatureExtract utility
     *
     * @param inputFileName the name with the extension of the stl file
     * @param featuresAngle angle to detect features
     * @return true if surfaceFeaturesDict is written, false otherwise
     */
    bool write_surfaceFeaturesDict(const std::string &inputFileName, const std::string &featuresAngle);

};


#endif //SNAPPYFILESWRITER_SURFACEFEATURESDICT_FILE_WRITER_H
