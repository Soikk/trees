#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main(){
  tree_t *t1 = createTree();
  addNode(t1->root, 1, 'l');
  addNode(t1->root, 2, 'r');
  addNode(t1->root->left, 11, 'l');
  addNode(t1->root->left->left, 111, 'l');
  addNode(t1->root->right, 22, 'r');
  addNode(t1->root->right, 21, 'l');
  printTree(*t1);
  printf("\nDepth: %d\n", treeDepth(*t1));
  printf("End node count: %d\n", endNodeCount(*t1));
  printf("Tree contains 2? %d\n", treeContainsN(*t1, 2));
  printf("Tree contains 3? %d\n", treeContainsN(*t1, 3));
  printf("Total number of nodes: %d\n", nodeCount(*t1));
  
  sortTree(t1);
  printf("Sorted tree:\n");
  printTree(*t1);
  printf("\n");
  return 0;

}
