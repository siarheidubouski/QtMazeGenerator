#pragma once

#include <vector>
#include "spanning_tree.h"

class Prims : public SpanningTree {
  private:
    void traverse(int, const Graph&);

  public:
    std::vector<std::pair<int, int>> createSpanningTree(int, const Graph&);
};
