#include "DecomposeParDict_Writer.h"

bool DecomposeParDict_Writer::write_decomposeParDict(std::string& fileName_without_extension){
    std::ofstream decomposeParDict;
    std::string path = "./snappyWD/"+ fileName_without_extension + "/system/decomposeParDict";
    decomposeParDict.open(path);
    if(decomposeParDict.is_open())
    {
        decomposeParDict << "/*--------------------------------*- C++ -*----------------------------------*\\ \n";
        decomposeParDict << "  =========                 | \n";
        decomposeParDict << "  \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox \n";
        decomposeParDict << "   \\\\    /   O peration     | Website:  https://openfoam.org \n";
        decomposeParDict << "    \\\\  /    A nd           | Version:  8 \n";
        decomposeParDict << "     \\\\/     M anipulation  | \n";
        decomposeParDict << " \\*---------------------------------------------------------------------------*/ \n";
        decomposeParDict << "FoamFile \n";
        decomposeParDict << "{ \n";
        decomposeParDict << "    version     2.0; \n";
        decomposeParDict << "    format      ascii; \n";
        decomposeParDict << "    class       dictionary; \n";
        decomposeParDict << "    location    \"system\"; \n";
        decomposeParDict << "    object      decomposeParDict; \n";
        decomposeParDict << "} \n";
        decomposeParDict << "// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * // \n";
        decomposeParDict << " \n";
        decomposeParDict << "numberOfSubdomains 4; \n";
        decomposeParDict << "\n";
        decomposeParDict << "method          ptscotch; // simple;\n";
        decomposeParDict << "\n";
        decomposeParDict << "simpleCoeffs\n";
        decomposeParDict << "{ \n";
        decomposeParDict << "    n               (2 2 1); \n";
        decomposeParDict << "    delta           0.001; \n";
        decomposeParDict << "}\n";
        decomposeParDict << "\n";
        decomposeParDict << "hierarchicalCoeffs\n";
        decomposeParDict << "{ \n";
        decomposeParDict << "    n               (1 1 1); \n";
        decomposeParDict << "    delta           0.001; \n";
        decomposeParDict << "    order           xyz; \n";
        decomposeParDict << "}\n";
        decomposeParDict << "\n";
        decomposeParDict << "metisCoeffs\n";
        decomposeParDict << "{ \n";
        decomposeParDict << "    processorWeights ( 1 1 1 1 ); \n";
        decomposeParDict << "}\n";
        decomposeParDict << "\n";
        decomposeParDict << "manualCoeffs\n";
        decomposeParDict << "{ \n";
        decomposeParDict << "     dataFile        \"\"; \n";
        decomposeParDict << "}\n";
        decomposeParDict << "\n";
        decomposeParDict << "distributed     no; \n";
        decomposeParDict << "\n";
        decomposeParDict << "roots           ( ); \n";
        decomposeParDict << "\n";
        decomposeParDict << "// ************************************************************************* //";
        decomposeParDict.close();
        return true;
    }
    return false;
}