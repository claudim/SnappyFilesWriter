#include "ControlDict_Writer.h"

bool ControlDict_Writer::write_controlDict(std::string& fileName_without_extension){
    std::ofstream controlDict_file;

    std::string path = "./snappyWD/"+ fileName_without_extension + "/system/controlDict";
    controlDict_file.open(path);
    if(controlDict_file.is_open())
    {
        controlDict_file << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
        controlDict_file << "  =========                 | \n";
        controlDict_file << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
        controlDict_file << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
        controlDict_file << "    \\\\  /    A nd           | Version:  8 \n";
        controlDict_file << "     \\\\/     M anipulation  | \n";
        controlDict_file << " \\*---------------------------------------------------------------------------*/ \n";
        controlDict_file << "FoamFile \n";
        controlDict_file << "{ \n";
        controlDict_file << "    version     2.0; \n";
        controlDict_file << "    format      ascii; \n";
        controlDict_file << "    class       dictionary; \n";
        controlDict_file << "    location    \"system\"; \n";
        controlDict_file << "    object      controlDict; \n";
        controlDict_file << "} \n";
        controlDict_file << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
        controlDict_file << " \n";
        controlDict_file << "application     icoFoam; \n";
        controlDict_file << " \n";
        controlDict_file << "startFrom       startTime; \n";
        controlDict_file << " \n";
        controlDict_file << "startTime       0; \n";
        controlDict_file << " \n";
        controlDict_file << "stopAt          endTime; \n";
        controlDict_file << " \n";
        controlDict_file << "endTime         50; \n";
        controlDict_file << " \n";
        controlDict_file << "deltaT          1; \n";
        controlDict_file << " \n";
        controlDict_file << "writeControl    timeStep; \n";
        controlDict_file << " \n";
        controlDict_file << "writeInterval   20; \n";
        controlDict_file << " \n";
        controlDict_file << "purgeWrite      0; \n";
        controlDict_file << " \n";
        controlDict_file << "writeFormat     ascii; \n";
        controlDict_file << " \n";
        controlDict_file << "writePrecision  6; \n";
        controlDict_file << " \n";
        controlDict_file << "writeCompression off; \n";
        controlDict_file << " \n";
        controlDict_file << "timeFormat      general; \n";
        controlDict_file << " \n";
        controlDict_file << "timePrecision   6; \n";
        controlDict_file << " \n";
        controlDict_file << "runTimeModifiable yes; \n";
        controlDict_file << " \n";
        controlDict_file << "// ************************************************************************* //";
        controlDict_file.close();
        return true;
    }
    return false;
}
