#include "Tree.hpp"

int main() {
  Tree tree;
  tree.add_operator_node(1, DUMMY_ROOT, Multiply);
  tree.add_operator_node(2, 1, Add);
  tree.add_operator_node(3, 1, Median);
  tree.add_operator_node(7, 2, Multiply);
  tree.add_operator_node(8, 2, Not);
  
  tree.add_operand_node(9, 8, 1);
  tree.add_operand_node(10, 7, 1);
  tree.add_operand_node(11, 7, 2);
  tree.add_operand_node(6, 3, 3);
  tree.add_operand_node(5, 3, 4);
  tree.add_operand_node(4, 3, 5);
   tree.add_operand_node(44, 3, 7);
  int result = tree.evaluate_tree();
  cout << result << endl; // output will be 11
}

/*
     +
    / \
   *   5
  / \
 2   3
2
*/
