#include <iostream>
#include "SurfaceFeaturesDict_File_Writer.h"
#include "ControlDict_Writer.h"
#include "FvSchemes_Writer.h"
#include "FvSolution_Writer.h"
#include "DecomposeParDict_Writer.h"
#include "MeshQualityDict_Writer.h"
#include "BlockMeshDict_Writer.h"
#include "SnappyHexMeshDict_Writer.h"

int main(int argc, char* argv[]) {

    int resolution;
    if(argc == 2 || argc == 3 || argc == 4) {
        //get the stl file name
        std::string inputPathFileName = argv[1];

        size_t startIndex  = inputPathFileName.find_last_of("/");
        std::string fileName_with_extension = inputPathFileName.substr(startIndex + 1,inputPathFileName.size());
        std::string fileName_without_extension = fileName_with_extension.substr(0,(fileName_with_extension.size()-4));

        std::string featuresAngle;
        if(argc == 3)
        {
            featuresAngle = argv[2];
        }
        else
        {
            featuresAngle = std::to_string(150);
        }

        if(argc == 4)
        {
            resolution = std::stoi(argv[3]);
        }
        else
        {
            resolution = 8;
        }

        //write the surfaceFeaturesDict
        SurfaceFeaturesDict_File_Writer surfaceFeaturesDictFileWriter;
        bool is_done = surfaceFeaturesDictFileWriter.write_surfaceFeaturesDict(fileName_with_extension, featuresAngle);
        std::cout<<is_done<<std::endl;
        std::cout<<"is_done"<<std::endl;
        
        ControlDict_Writer controlDictWriter;
        bool is_written_controlDict = controlDictWriter.write_controlDict(fileName_without_extension);
        std::cout<<is_written_controlDict<<std::endl;
        
        FvSchemes_Writer fvSchemesWriter;
        bool is_written_fvSchemes = fvSchemesWriter.write_fvSchemes(fileName_without_extension);
        std::cout<<is_written_fvSchemes<<std::endl;

        FvSolution_Writer fvSolutionWriter;
        bool is_written_fvSolution = fvSolutionWriter.write_fvSolution(fileName_without_extension);
        std::cout<<is_written_fvSolution<<std::endl;
        
        DecomposeParDict_Writer decomposeParDictWriter;
        bool is_written_decomposeParDict = decomposeParDictWriter.write_decomposeParDict(fileName_without_extension);
        std::cout<<is_written_decomposeParDict<<std::endl;
        
        MeshQualityDict_Writer meshQualityDictWriter;
        bool is_written_meshQualityDict = meshQualityDictWriter.write_meshQualityDict(fileName_without_extension);
        std::cout<<is_written_meshQualityDict<<std::endl;

        BlockMeshDict_Writer blockMeshDictWriter;
        bool is_written_blocKMeshDict = blockMeshDictWriter.write_blockMeshDict(inputPathFileName,resolution);
        std::cout<<is_written_blocKMeshDict<<std::endl;

        std::map<std::string, std::string > snappyHexMeshDict_parameters;
        snappyHexMeshDict_parameters["FILENAME_WITHOUT_EXTENSION"] = fileName_without_extension;
        snappyHexMeshDict_parameters["FILENAME_WITH_EXTENSION"] = fileName_without_extension + ".stl" ;
        std::string location_in_mesh = std::to_string(blockMeshDictWriter.getPolyhedronInternalPoint().x()) + " " + std::to_string(
                blockMeshDictWriter.getPolyhedronInternalPoint().y()) + " " + std::to_string(
                blockMeshDictWriter.getPolyhedronInternalPoint().z());
        snappyHexMeshDict_parameters["LOCATION_IN_MESH"] = location_in_mesh ;
        SnappyHexMeshDict_Writer snappyHexMeshDictWriter;
        bool is_written_snappyHexMeshDict = snappyHexMeshDictWriter.write_snappyHexMeshDict(snappyHexMeshDict_parameters);
        std::cout<<is_written_snappyHexMeshDict<<std::endl;
    }
    if(argc<2)
    {
        std::cout << "Too few arguments" <<std::endl;
        std::cout << "You have to pass: inputSTLFile. Optionally featuresAngle and resolution " <<std::endl;
    }
    if(argc > 4)
    {
        std::cout << "Too many arguments" << std::endl;
        std::cout << "You have to pass: inputSTLFile. Optionally featuresAngle and resolution " <<std::endl;
    }


    return 0;
}


