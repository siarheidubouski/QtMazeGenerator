#pragma once

#include <vector>
#include "spanning_tree.h"

class BFS : public SpanningTree {
  private:
    std::vector<bool> visited_;
    std::vector<int> currentLevel_;
    std::vector<int> nextLevel_;

  public:
    std::vector<std::pair<int, int>> createSpanningTree(int, const Graph&);
};
