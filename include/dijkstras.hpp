#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using node_t = std::pair<int, std::string>;
using node_collection = std::vector<node_t>;
using graph_t = std::unordered_map<std::string, node_collection>;

struct results
{
  std::vector<std::string> path;
  unsigned long int min_cost;
};

results dijkstras(graph_t&, const std::string&, const std::string&);
