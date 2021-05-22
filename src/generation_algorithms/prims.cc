#include <algorithm>
#include "prims.h"

void traverse(int vertices, const Graph& adjList) {
  std::vector<bool> visited_(vertices, false);
  std::vector<std::pair<int, int>> boundary;
  int startVertex = std::uniform_distribution<int>(0, vertices - 1)(generator);

  for (int i = 1; i < vertices; i++) {
    visited_[startVertex] = true;

    for (auto edge: adjList[startVertex]) {
      if (edge.first != -1 && !visited_[first]) {
        boundary.push_back({startVertex, edge.first});
      }
    }

    std::pair<int, int> nextEdge = {-1, 1};

    for (; nextEdge.first == -1;) {
      int index = std::uniform_int_distribution<int>(0, boundary.size() - 1)(generator);
      std::swap(boundary[index], boundary.back());

      if (!visited_[boundary.back().second]) nextEdge = boundary.back();
      boundary.pop_back();
    }

    spanningTree_.push_back(nextEdge);
    startVertex = nextEdge.second;
  }
}

std::vector<std::pair<int, int>> Prims::createSpanningTree(
    int vertices, const Graph& adjList) {

  spanningTree_.clear();
  traverse(vertices, adjList);

  return spanningTree_;
}

