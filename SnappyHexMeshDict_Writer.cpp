#include "SnappyHexMeshDict_Writer.h"

bool SnappyHexMeshDict_Writer::write_snappyHexMeshDict(std::map<std::string, std::string >& snappyHexMeshDict_parameters) {

    std::ifstream filein("./DictionariesExamples/snappyHexMeshDict");
    std::string dst_path ="./snappyWD/"+ snappyHexMeshDict_parameters["FILENAME_WITHOUT_EXTENSION"] + "/system/snappyHexMeshDict";
    std::ofstream fileout(dst_path);
    std::string contents = getfile(filein);
    for(std::map<std::string, std::string>::iterator it = snappyHexMeshDict_parameters.begin(), it_end = snappyHexMeshDict_parameters.end(); it != it_end; ++it)
    {
        find_and_replace(contents, it->first, it->second);
    }
    fileout << contents;

    return true;
}

std::string SnappyHexMeshDict_Writer::getfile(std::ifstream& fileName) {
    std::string contents;
    // Here fileName one way to read the whole file
    for (char ch; fileName.get(ch); contents.push_back(ch)) {}
    return contents;
}

void SnappyHexMeshDict_Writer::find_and_replace(std::string& file_contents, const std::string& wordToReplace, const std::string& wordToInsert) {
    // This searches the file for the first occurence of the wordToReplace string.
    auto pos = file_contents.find(wordToReplace);
    while (pos != std::string::npos) {
        file_contents.replace(pos, wordToReplace.length(), wordToInsert);
        // Continue searching from here.
        pos = file_contents.find(wordToReplace, pos);
    }
}