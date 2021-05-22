#pragma once

#include <vector>
#include "spanning_tree.h"

class DFS : public SpanningTree {
  private:
    std::vector<bool> visited_;
    void traverse(int, const Graph&);

  public:
    std::vector<std::pair<int, int>> createSpanningTree(int, const Graph&);
};
