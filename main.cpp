#include <iostream>

#include "graph.hpp"
#include "dijkstras.hpp"

void app() {
  using GraphPlusPlus::Graph;
  using GraphPlusPlus::node_collection;
  using GraphPlusPlus::unordered_graph_primitive_t;

  // Use graph from the following YT video:
  // https://youtu.be/_lHSawdgXpI
  unordered_graph_primitive_t ugraph;

  ugraph.insert(std::make_pair("A", node_collection{{4, "B"}, {2, "C"}}));
  ugraph.insert(
      std::make_pair("B", node_collection{{3, "C"}, {2, "D"}, {3, "E"}}));
  ugraph.insert(
      std::make_pair("C", node_collection{{1, "B"}, {4, "D"}, {5, "E"}}));
  ugraph.insert(std::make_pair("D", node_collection{}));
  ugraph.insert(std::make_pair("E", node_collection{{1, "D"}}));

  Graph graph(ugraph);

  // Run Dijkstra's algorithm on the aforementioned graph & collect results from
  // the run
  auto gp_graph = graph.get_as_unordered_map();
  results res = dijkstras(gp_graph, "A", "D");

  std::cout << "Cost: " << res.min_cost << std::endl;
  std::cout << "Path:" << std::endl;

  // Printing out results
  auto &path = res.path;
  for (auto it = path.begin(); it != path.end(); ++it) {
    std::cout << (it != path.begin() ? "->" : "") << *it;
  }
  std::cout << std::endl;
}

int main() {
  app();

  return 0;
}
