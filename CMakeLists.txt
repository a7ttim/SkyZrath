cmake_minimum_required(VERSION 3.5)

# Project title and define versioning
project(SkyZrath)

#Use C++17
set(CMAKE_CXX_STANDARD 17)

# Unit tests
file(GLOB SkyZrathCore_source src/*.cpp src/*.h)
add_library(SkyZrathCore STATIC ${SkyZrathCore_source})
add_executable(SkyZrath ${SkyZrathCore_source})

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Dependencies
find_package(Boost 1.75 REQUIRED COMPONENTS unit_test_framework)
enable_testing()

list(APPEND TestsList HexagonalTest MapTest)

foreach(SkyZrathCoreTest IN LISTS TestsList)
# Gather the header and source files
file(GLOB UNIT_TESTS_SRC_FILES test/${SkyZrathCoreTest}.cpp)

add_executable(${SkyZrathCoreTest} ${UNIT_TESTS_SRC_FILES})

# indicates the include paths
target_include_directories(${SkyZrathCoreTest} PRIVATE ${Boost_INCLUDE_DIRS} ${SkyZrathCore_source})
# indicates the shared library variant
target_compile_definitions(${SkyZrathCoreTest} PRIVATE "BOOST_TEST_DYN_LINK=1")
# indicates the link paths
target_link_libraries(${SkyZrathCoreTest} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} SkyZrathCore)

# declares a test with our executable
add_test(NAME ${SkyZrathCoreTest} COMMAND ${SkyZrathCoreTest})
endforeach()