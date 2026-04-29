cmake_minimum_required(VERSION 3.16)

project(Programiranje2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Programiranje2 
	"constants.h"
	"napredno.cpp"
    "srecanje1.cpp" 
    "srecanje1_naloge.cpp" 
	"srecanje2.cpp" 
    "srecanje3.cpp" 
    "srecanje4.cpp" 
    "prim_dijkstra.cpp" "AVL-tree.cpp" "srecanje3_naloge.cpp" "srecanje4_naloge.cpp" "nacrtovalski_vzorci.cpp" "solid.cpp")

include(GNUInstallDirs)
install(TARGETS Programiranje2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
