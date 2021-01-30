cmake_minimum_required(VERSION 3.16)
project(SnappyFilesWriter)

set(CMAKE_CXX_STANDARD 20)

# Find CGAL
find_package(CGAL REQUIRED COMPONENTS Core) # If the dependency is required, use REQUIRED option - if it's not found CMake will issue an error
include( ${CGAL_USE_FILE} )

SET(HEADER_FILES
        SurfaceFeaturesDict_File_Writer.h
        FvSchemes_Writer.h
        FvSolution_Writer.h
        DecomposeParDict_Writer.h
        MeshQualityDict_Writer.h
        BlockMeshDict_Writer.h
        STL_Reader.h
        SnappyHexMeshDict_Writer.h
        Vertex_location_finder.h
        )

SET(SOURCE_FILES
        SurfaceFeaturesDict_File_Writer.cpp
        ControlDict_Writer.h ControlDict_Writer.cpp
        FvSchemes_Writer.cpp
        FvSolution_Writer.cpp
        DecomposeParDict_Writer.cpp
        MeshQualityDict_Writer.cpp
        BlockMeshDict_Writer.cpp
        SnappyHexMeshDict_Writer.cpp
        Vertex_location_finder.cpp
        )


add_executable(SnappyFilesWriter main.cpp  ${HEADER_FILES}   ${SOURCE_FILES}  )
#add_executable(SnappyFilesWriter main.cpp SurfaceFeaturesDict_File_Writer.h SurfaceFeaturesDict_File_Writer.cpp ControlDict_Writer.h ControlDict_Writer.cpp FvSchemes_Writer.h FvSchemes_Writer.cpp FvSolution_Writer.cpp FvSolution_Writer.h DecomposeParDict_Writer.cpp DecomposeParDict_Writer.h MeshQualityDict_Writer.cpp MeshQualityDict_Writer.h BlockMeshDict_Writer.cpp BlockMeshDict_Writer.h STL_Reader.h  SnappyHexMeshDict_Writer.h SnappyHexMeshDict_Writer.cpp)