#include "MeshQualityDict_Writer.h"

bool MeshQualityDict_Writer::write_meshQualityDict(std::string& fileName_without_extension){
    std::ofstream meshQualityDict_file;
    std::string path = "./snappyWD/"+ fileName_without_extension + "/system/meshQualityDict";
    meshQualityDict_file.open(path);
    if(meshQualityDict_file.is_open())
    {
        meshQualityDict_file << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
        meshQualityDict_file << "  =========                 | \n";
        meshQualityDict_file << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
        meshQualityDict_file << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
        meshQualityDict_file << "    \\\\  /    A nd           | Version:  8 \n";
        meshQualityDict_file << "     \\\\/     M anipulation  | \n";
        meshQualityDict_file << " \\*---------------------------------------------------------------------------*/ \n";
        meshQualityDict_file << "FoamFile \n";
        meshQualityDict_file << "{ \n";
        meshQualityDict_file << "    version     2.0; \n";
        meshQualityDict_file << "    format      ascii; \n";
        meshQualityDict_file << "    class       dictionary; \n";
        meshQualityDict_file << "    location    \"system\"; \n";
        meshQualityDict_file << "    object      meshQualityDict; \n";
        meshQualityDict_file << "} \n";
        meshQualityDict_file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
        meshQualityDict_file << " \n";
        meshQualityDict_file << "// Include defaults parameters from master dictionary \n";
        meshQualityDict_file << "#includeEtc \"caseDicts/mesh/generation/meshQualityDict\" \n";
        meshQualityDict_file << " \n";
        meshQualityDict_file << "// ************************************************************************* //";
        meshQualityDict_file.close();
        return true;
    }
    return false;
}
