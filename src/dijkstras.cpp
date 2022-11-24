#include <queue>
#include <unordered_set>
#include <vector>

#include "dijkstras.hpp"

results dijkstras(graph_t &graph, const std::string &start,
                  const std::string &target) {
  std::unordered_map<std::string, int> costs;

  // Min Heap (use (node + edge) weight to determine priority)
  std::priority_queue<node_t, std::vector<node_t>, std::greater<node_t>> mqueue;

  // Populate the costs for each node in graph
  for (const auto &node : graph) {
    const auto [node_name, collection] = node;
    costs.insert(std::make_pair(node_name, node_name == start ? 0 : 99999));
  }

  mqueue.emplace(std::make_pair(0, start));

  results res;
  std::vector<std::string> path;
  std::unordered_set<std::string> visited;
  std::string last_node = "";

  while (!mqueue.empty()) {
    // Extract node with the lowest edge weight
    const auto node = mqueue.top();
    const auto node_cost = node.first;
    const auto node_name = node.second;
    mqueue.pop();

    visited.insert(node_name);

    // Check to see if we made it to the target node
    // populate the result struct if we did & return
    if (node_name == target) {
      path.push_back(node_name);

      res.path = std::move(
          std::vector<std::string>(std::make_move_iterator(path.begin()),
                                   std::make_move_iterator(path.end())));

      res.min_cost = node_cost;

      return res;
    }

    if (last_node != "")
      path.push_back(last_node);

    // Check all neighbors of the current node
    // update costs, and emplace back unvisited neighbors into the heap
    for (const auto &neighbor : graph[node_name]) {
      const auto neighbor_cost = neighbor.first;
      const auto neighbor_name = neighbor.second;

      // Update costs
      const auto cur_cost = costs[neighbor_name];
      const auto mcost = node_cost + neighbor_cost;
      costs[neighbor_name] = std::min(cur_cost, mcost);

      // Push back current neighbor if we didn't visit it yet
      if (visited.find(neighbor_name) == visited.end())
        mqueue.emplace(std::make_pair(mcost, neighbor_name));

      last_node = node_name;
    }
  }

  // defaults if we didn't find a path to the target node
  res.path = path;
  res.min_cost = 9999;

  return res;
}
