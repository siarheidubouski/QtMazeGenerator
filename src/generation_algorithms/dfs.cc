#include <algorithm>
#inlcude "dfs.h"

void DFS::traverse(int vertex, const Graph& adjList) {
  visited_[vertex] = true;
  std::vector<int> nodeOrder(adjList[vertex].size());

  std::iota(nodeOrder.begin(), nodeOrder.end(), 0);
  std::shuffle(nodeOrder.begin(), nodeOrder.end(), generator);

  for (auto index: nodeOrder) {
    int nextVertex = adjList[vertex][index].first;

    if ( !(nextVertex < 0 || visited_[nextVertex]) ) {
      spanningTree_.push_back({vertex, nextVertex});
    }

    traverse(nextVertex, adjList);
  }
}


std::vector<std::pair<int, int>> DFS::createSpanningTree(int vertices, const Graph&) {
  spanningTree_.clear();
  visited_ = std::vector<bool>(vertices, false);

  int startVertex = std::uniform_int_distribution<int>(0, vertices - 1)(generator);

  traverse(startVertex, adjList);

  return spanningTree_;
}
