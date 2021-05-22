#include "spanning_tree.h"

SpanningTree::SpanningTree() {
  generator_ = std::mt19937(randDevice());
}
