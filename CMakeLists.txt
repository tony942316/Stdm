cmake_minimum_required(VERSION 3.28)

project(Stdm
    VERSION 0.9.0
    DESCRIPTION "C++ Standard Library As Modules"
    LANGUAGES CXX)

message("Compiler is: ${CMAKE_CXX_COMPILER_ID}")

add_subdirectory(OSHeader)
add_subdirectory(OSm)
add_subdirectory(Stdm)
add_subdirectory(StdHeader)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_library(Tests STATIC)
    target_sources(Tests
        PUBLIC FILE_SET CXX_MODULES FILES
            Tests.cpp)

    target_compile_features(Tests PUBLIC cxx_std_20)
    target_link_libraries(Tests PUBLIC Stdm OSm)

    set_target_properties(Tests PROPERTIES
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)

    add_executable(ModMain)
    target_sources(ModMain PRIVATE ModMain.cpp)
    target_compile_features(ModMain PRIVATE cxx_std_20)
    target_link_libraries(ModMain PRIVATE Tests)
    set_target_properties(ModMain PROPERTIES
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)

    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(GMF INTERFACE
            /W4 /WX
            /GR-)
    else ()
        target_compile_options(GMF INTERFACE
            -Wall -Wextra -Wpedantic -Wconversion
            -Werror
            -fno-rtti)
    endif()

    add_executable(Isolate)
    target_sources(Isolate PRIVATE Isolate.cpp)
    target_compile_features(Isolate PRIVATE cxx_std_20)
    target_link_libraries(Isolate PRIVATE Stdm)

    set_target_properties(Isolate PROPERTIES
        CXX_STANDARD_REQUIRED On
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)

    add_executable(HeaderMain)
    target_sources(HeaderMain PRIVATE HeaderMain.cpp)
    target_link_libraries(HeaderMain PRIVATE StdHeader)

    set_target_properties(HeaderMain PROPERTIES
        CXX_EXTENSIONS Off
        EXPORT_COMPILE_COMMANDS On)
endif()
