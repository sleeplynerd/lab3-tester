project( tests )
include_directories( ${PROJECT_BINARY_DIR}/../src )
add_executable( tests main.cpp )
target_link_libraries( tests src )
