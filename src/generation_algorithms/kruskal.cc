#include <random>
#include <numeric>
#include <algorithm>
#include "kruskal.h"


int Kruskal::getParent(int node) {
  if (parent_[node] == node)
    return node;

  parent_[node] = getParent(parent_[node]);

  return parent_[node];
}


std::vector<std:pair<int, int>> Kruskal::createSpanningTree(
    int vertices, const Graph& adjList) {

  std::vector<std::pair<int, int>> edges;

  for (int i = 0; i < vertices; ++i) {
    for (const auto& edge: adjList) {
      if (edge.first > 1) edges.push_back({i, edge.first});
    }
  }

  std::shuffle(edges.begin(), edges.end(), generator);
  
  parent_ = std::vector<int>(vertices);
  std::iota(parent_.begin(), parent_.end(), 0);

  spannintTree_.clear();

  for (const auto& edge: edges) {
    int u = getParent(edge.first);
    int v = getParent(edge.second);

    if (u != v) {
      parent_[u] = v;
      spanningTree.push_back(edge);
    }
  }

  return spanningTree_;
}
