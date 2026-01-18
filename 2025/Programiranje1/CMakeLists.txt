cmake_minimum_required(VERSION 3.16)

project(Programiranje1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Programiranje1 
    "128Nalog.cpp"
	"constants.h"
	"srecanje2.cpp"
	"srecanje3.cpp"
	"srecanje4.cpp"
	"srecanje5.cpp"
	"srecanje6.cpp"
	"srecanje7.cpp"
	"Primer1/AppException.h" 
	"Primer1/AppException.cpp" 
	"Primer1/FileOpenException.h" 
	"Primer1/FileOpenException.cpp" 
	"Primer1/CsvFormatException.h" 
	"Primer1/CsvFormatException.cpp" 
	"Primer1/InvalidFieldException.h" 
	"Primer1/InvalidFieldException.cpp" 
	"Primer1/Student.h" 
	"Primer1/Student.cpp" 
	"Primer1/CsvReader.h" 
	"Primer1/CsvReader.cpp" 
	"Primer1/main.cpp"
)

include(GNUInstallDirs)
install(TARGETS Programiranje1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
