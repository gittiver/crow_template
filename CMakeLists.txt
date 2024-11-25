cmake_minimum_required(VERSION 3.21)

if (POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif ()

if (POLICY CMP0126)
    cmake_policy(SET CMP0126 NEW)
endif ()

project(crow-template VERSION 0.0.1 LANGUAGES CXX)

enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

option(${PROJECT_NAME}_ENABLE_TESTS "enable testing" OFF)

CPMAddPackage(Crow
  VERSION 1.2.0
  GITHUB_REPOSITORY CrowCpp/Crow
  OPTIONS
  "CROW_BUILD_EXAMPLES Off"
  "CROW_BUILD_TOOLS Off"
  "CROW_BUILD_TESTS Off"
  "CROW_BUILD_DOCS Off"
  "CROW_ENABLE_COMPRESSION On"
  "CROW_ENABLE_SSL On"
)

include(CTest)
enable_testing()

CPMAddPackage(Catch2
  VERSION 3.7.0
  GITHUB_REPOSITORY catchorg/Catch2
  OPTIONS
  "CATCH_INSTALL_DOCS Off"
  "CATCH_INSTALL_EXTRAS Off"
  "CATCH_ENABLE_REPRODUCIBLE_BUILD Off"
)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Crow::Crow
        )
