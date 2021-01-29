// Copyright (c) 2020-2021 Univaq (Italy)
// All rights reserved.
//
// Author(s): Claudia Di Marco <dimarco.claud@gmail.com>, Riccardo Mantini <mantini.riccardo@gmail.com>
//
//******************************************************************************
// File Description :
// Write a snappyHexMeshDict useful for the OpenFOAM SnappyHexMesh utilities
//******************************************************************************

#ifndef SNAPPYFILESWRITER_SNAPPYHEXMESHDICT_WRITER_H
#define SNAPPYFILESWRITER_SNAPPYHEXMESHDICT_WRITER_H

#include <map>
#include "fstream"


class SnappyHexMeshDict_Writer {

public:
    /**
     * @brief Write the snappyHexMeshDict
     *
     * @return true if snappyHexMeshDict is written, false otherwise
     */
    bool write_snappyHexMeshDict(std::map<std::string, std::string >& snappyHexMeshDict_parameters);

    /**
     * @brief Read the entire file into a string.
     *
     * @param fileName The name of the file to read
     * @return The entire file into a string
     */
    std::string getfile(std::ifstream& fileName);

    /**
     * @brief Find the given wordToReplace in the string (file_contents) and replace it with wordToInsert.
     *
     * @param file_contents The string
     * @param wordToReplace Word to search to replace with another word.
     * @param wordToInsert Word used to replace the searched word.
     */
    void find_and_replace(std::string& file_contents, const std::string& wordToReplace, const std::string& wordToInsert);
};


#endif //SNAPPYFILESWRITER_SNAPPYHEXMESHDICT_WRITER_H
