cmake_minimum_required(VERSION 3.2)

include(FetchContent)
include(CheckCXXCompilerFlag)

project(
    Gravity2D
    VERSION "0.1"
    HOMEPAGE_URL "https://github.com/ollirelander/Gravity2D"
    DESCRIPTION "2D gravity simulation written in modern C++17"
    LANGUAGES CXX
)

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

file (GLOB_RECURSE CPP_SOURCE_FILES
	"./source/*"
)

if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    set(OPTIONS -Wall -Wextra -pedantic-errors -Werror)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(OPTIONS /W4 /WX)
    if(HAS_PERMISSIVE_FLAG)
        set(OPTIONS ${OPTIONS} /permissive-)
    endif()
endif()

add_executable(${PROJECT_NAME} "main.cpp" ${CPP_SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE ${OPTIONS})
target_include_directories(${PROJECT_NAME} PRIVATE "./include" "./external/SFML/include" "./external/SFML/src")
