#include "graph.hpp"

using GraphPlusPlus::Node;
using GraphPlusPlus::Edge;
using GraphPlusPlus::Graph;

Graph::Graph() : weighted(false), directed(false)
{
}

Graph::Graph(bool _weighted, bool _directed) : weighted(_weighted), directed(_directed)
{
}

Graph::Graph(const graph_primitive_t& graph_p)
{
}

Graph::Graph(const unordered_graph_primitive_t& graph_p)
{
}

Graph::~Graph()
{
}

void Graph::add_node(const std::string& node)
{
}

void Graph::add_node(const std::string& node, const double weight)
{
}

void Graph::add_edge(const std::string& node_1, const std::string& node_2)
{
}

void Graph::add_edge(const std::string& node_1, const std::string& node_2, const double weight)
{
}

GraphPlusPlus::graph_primitive_t Graph::get_as_map() const
{
    return graph_primitive_t();
}

GraphPlusPlus::unordered_graph_primitive_t Graph::get_as_unordered_map() const
{
    return unordered_graph_primitive_t();
}

std::unordered_set<std::string> Graph::get_nodes() const
{
    return i_nodes;
}

std::unordered_set<std::string> Graph::get_edges() const
{
    return i_edges;
}
