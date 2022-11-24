add_library(dijkstras STATIC dijkstras.cpp)
target_include_directories(dijkstras PRIVATE ${CMAKE_SOURCE_DIR}/include)
