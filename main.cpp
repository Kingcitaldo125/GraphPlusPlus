#include <iostream>

#include "dijkstras.hpp"

void app()
{
  graph_t graph;

  // Use graph from the following YT video:
  // https://youtu.be/_lHSawdgXpI
  graph.insert(std::make_pair("A", node_collection{{4,"B"}, {2,"C"}}));
  graph.insert(std::make_pair("B", node_collection{{3,"C"}, {2,"D"}, {3,"E"}}));
  graph.insert(std::make_pair("C", node_collection{{1,"B"}, {4,"D"}, {5,"E"}}));
  graph.insert(std::make_pair("D", node_collection{}));
  graph.insert(std::make_pair("E", node_collection{{1,"D"}}));

  // Run Dijkstra's algorithm on the aforementioned graph & collect results from the run
  results res = dijkstras(graph, "A", "D");

  std::cout << "Cost: " << res.min_cost << std::endl;
  std::cout << "Path:" << std::endl;

  // Printing out results
  auto& path = res.path;
  for (auto it = path.begin(); it != path.end(); ++it)
  {
    std::cout << (it != path.begin() ? "->" : "") << *it;
  }
  std::cout << std::endl;
}


int main()
{
  app();

  return 0;
}
