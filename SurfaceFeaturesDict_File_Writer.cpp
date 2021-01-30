#include "SurfaceFeaturesDict_File_Writer.h"

bool SurfaceFeaturesDict_File_Writer::write_surfaceFeaturesDict(const std::string &inputFileName, const std::string &featuresAngle) {
    std::ofstream surfaceFeaturesDict_file;
    std::string fileName_with_extension = inputFileName;
    std::string fileName_without_extension = inputFileName.substr(0,(fileName_with_extension.size()-4));

    std::string path = "./snappyWD/"+ fileName_without_extension + "/system/surfaceFeaturesDict";
    surfaceFeaturesDict_file.open(path);
    if(surfaceFeaturesDict_file.is_open())
    {
        surfaceFeaturesDict_file << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
        surfaceFeaturesDict_file << "  =========                 | \n";
        surfaceFeaturesDict_file << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
        surfaceFeaturesDict_file << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
        surfaceFeaturesDict_file << "    \\\\  /    A nd           | Version:  8 \n";
        surfaceFeaturesDict_file << "     \\\\/     M anipulation  | \n";
        surfaceFeaturesDict_file << "\\*---------------------------------------------------------------------------*/ \n";
        surfaceFeaturesDict_file << "FoamFile \n";
        surfaceFeaturesDict_file << "{ \n";
        surfaceFeaturesDict_file << "    version     2.0; \n";
        surfaceFeaturesDict_file << "    format      ascii; \n";
        surfaceFeaturesDict_file << "    class       dictionary; \n";
        surfaceFeaturesDict_file << "    object      surfaceFeaturesDict; \n";
        surfaceFeaturesDict_file << "} \n";
        surfaceFeaturesDict_file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
        surfaceFeaturesDict_file << " \n";
        surfaceFeaturesDict_file << "surfaces (\"" << inputFileName << "\");\n";
        surfaceFeaturesDict_file << "\n";
        surfaceFeaturesDict_file << "// Identify a feature when angle between faces < includedAngle \n";
        surfaceFeaturesDict_file << "includedAngle "<< featuresAngle << "\n";
        surfaceFeaturesDict_file << " \n";
        surfaceFeaturesDict_file << "// ************************************************************************* //";
        surfaceFeaturesDict_file.close();
        return true;
    }
    return false;



}