#pragma once

#include <vector>
#include <random>
#include <memory>
#include "cellboarder"

using Graph = std::vector<std::vector<std::pair<int, std::shared_ptr<CellBoarder>>>;

class SpanningTree {
  protected:
    std::vector<std::pair<int, int>> spanningTree_;
    std::random_device randDevice;
    std::mt19937 generator_;

  public:
    SpanningTree() = default;
    virtual std::vector<std::pair<int, int> createSpanningTree(int, const Graph& ) = 0;
};
