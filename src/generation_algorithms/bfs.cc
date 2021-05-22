#include <iostream>
#include <algorithm>
#include "BFS.h"

std::vector<std::pair<int, int>> BFS::createSpanningTree(
    int vertices, const Graph& adjList) {

  visited_ = std::vector<bool>(vertices, false);

  int startVertex = std::uniform_int_distribution<int>(0, vertices - 1)(generator);

  currentLevel_.push_back(startVertex);
  visited_[startVertex] = true;

  spanningTree_.clear();

  while (!currentLevel_.empty()) {
    for (auto vertex: currentLevel_) {
      for (const auto& edge: adjList[vertex]) {
        int nextVertex = edge.first;

        if (nextVertex < 0 || visited_[nextVertex]) {
          continue;
        }

        visited_[nextVertex] = true;
        spanningTree_.push_back({vertex, nextVertex});
        nextLevel_.push_back(nextVertex);
      }
    }

    currentLevel_.clear();
    std::swap(currentLevel_, nextLevel_);
    std::shuffle(currentLevel_.begin(), currentLevel_.end(), generator);
  }

  return spanningTree_;
}
