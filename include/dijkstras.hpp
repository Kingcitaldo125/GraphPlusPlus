#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "graph.hpp"

struct results {
  std::vector<std::string> path;
  unsigned long int min_cost;
};

results dijkstras(GraphPlusPlus::unordered_graph_primitive_t&, const std::string&, const std::string&);
