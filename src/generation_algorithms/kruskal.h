#pragma once

#include <vector>
#include "spanning_tree.h"

class Kruskal : public SpanningTree {
  private:
    std::vector<int> parent_;
    int getParent(int);

  public:
    std::vector<std::pair<int, int>> createSpanningTree(int, const Graph&);
};
