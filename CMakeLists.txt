cmake_minimum_required(VERSION 3.7...3.23)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# ---- Project ----

project(fast_float_proxy LANGUAGES CXX)

option(FAST_FLOAT_EXAMPLES "whether or not to build the examples" ON)

# ---- Fetch CPM ----

set(CPM_DOWNLOAD_VERSION 0.27.2)
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake v${CPM_DOWNLOAD_VERSION}")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# ---- Add dependencies via CPM ----
# See https://github.com/TheLartians/CPM.cmake for details and examples

CPMAddPackage(
  NAME fast_float
  GITHUB_REPOSITORY fastfloat/fast_float
  GIT_TAG v0.7.0
)

CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY sthagen/doctest
  GIT_TAG 2020.12
)

# ---- Create binary ----

add_executable(fast_float_test main.cpp)
target_link_libraries(fast_float_test doctest fast_float)
set_target_properties(fast_float_test PROPERTIES CXX_STANDARD 17)

# ---- Enable testing ----

enable_testing() 
add_test(fast_float_test fast_float_test)

# ---- Create the examples ----

message(STATUS "Note the fetched includes are taken from below: ${FETCHCONTENT_BASE_DIR}")
if (FAST_FLOAT_EXAMPLES)
    macro(fast_float_examples EXAMPLENAME)
        add_executable(${EXAMPLENAME} ${ARGN})
        set_target_properties(${EXAMPLENAME} PROPERTIES FOLDER examples)
        set_target_properties(${EXAMPLENAME} PROPERTIES CXX_STANDARD 17)
        target_include_directories(${EXAMPLENAME} PUBLIC "${FETCHCONTENT_BASE_DIR}/fast_float-src/include")
        add_test(NAME ${EXAMPLENAME} COMMAND ${EXAMPLENAME})
    endmacro()
    add_subdirectory(examples)
endif()
