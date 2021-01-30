#include "FvSolution_Writer.h"

bool FvSolution_Writer::write_fvSolution(std::string& fileName_without_extension) {
    std::ofstream fvSchemes_file;
    std::string path = "./snappyWD/"+ fileName_without_extension + "/system/fvSolution";
    fvSchemes_file.open(path);
    if(fvSchemes_file.is_open())
    {
        fvSchemes_file << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
        fvSchemes_file << "  =========                 | \n";
        fvSchemes_file << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
        fvSchemes_file << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
        fvSchemes_file << "    \\\\  /    A nd           | Version:  8 \n";
        fvSchemes_file << "     \\\\/     M anipulation  | \n";
        fvSchemes_file << " \\*---------------------------------------------------------------------------*/ \n";
        fvSchemes_file << "FoamFile \n";
        fvSchemes_file << "{ \n";
        fvSchemes_file << "    version     2.0; \n";
        fvSchemes_file << "    format      ascii; \n";
        fvSchemes_file << "    class       dictionary; \n";
        fvSchemes_file << "    location    \"system\"; \n";
        fvSchemes_file << "    object      fvSolution; \n";
        fvSchemes_file << "} \n";
        fvSchemes_file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
        fvSchemes_file << "// ************************************************************************* //";
        fvSchemes_file.close();
        return true;
    }
    return false;
}