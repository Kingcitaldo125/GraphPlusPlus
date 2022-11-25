#pragma once

#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace GraphPlusPlus {

using node_t = std::pair<int, std::string>;
using node_collection = std::vector<node_t>;
using graph_primitive_t = std::map<std::string, node_collection>;
using unordered_graph_primitive_t = std::unordered_map<std::string, node_collection>;

struct Node
{
    std::string id;
    std::unordered_set<std::string> connections;
};

struct Edge
{
    std::pair<std::string,std::string> nodes;
    double weight;
};

class Graph
{
 public:
    Graph();
    Graph(bool _weighted, bool _directed);
    Graph(const graph_primitive_t& graph_p);
    Graph(const unordered_graph_primitive_t& graph_p);

    virtual ~Graph();

    virtual void add_node(const std::string&);
    virtual void add_node(const std::string&, const double);

    virtual void add_edge(const std::string&, const std::string&);
    virtual void add_edge(const std::string&, const std::string&, const double);

    graph_primitive_t get_as_map() const;
    unordered_graph_primitive_t get_as_unordered_map() const;

    std::unordered_set<std::string> get_nodes() const;
    std::unordered_set<std::string> get_edges() const;

 private:
    // internal graph data structs
    unordered_graph_primitive_t internal;

    // keep track of currently tracked nodes/edges
    std::unordered_set<std::string> i_nodes;
    std::unordered_set<std::string> i_edges;

    // general graph properties
    bool weighted;
    bool directed;
};

} // GraphPlusPlus
