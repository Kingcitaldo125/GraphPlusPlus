# Primary graph target
add_library(graph STATIC graph.cpp)

# Propagate local include directory information to downstream targets
target_include_directories(graph PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Dijkstras algorithm target
add_library(dijkstras STATIC dijkstras.cpp)

target_link_libraries(dijkstras PRIVATE graph)
