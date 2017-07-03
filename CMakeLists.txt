include_directories(${PROJECT_SOURCE_DIR}/src)
cmake_minimum_required( VERSION 2.6. )
set( CMAKE_CXX_STANDARD 11 )

add_subdirectory( VARIANTS )
add_subdirectory( src )
add_subdirectory( test )
