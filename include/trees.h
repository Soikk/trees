#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node *left;
  struct node *right;
} node_t;

typedef struct tree{
  node_t *root;
} tree_t;


node_t* createNode(int val);

tree_t* createTree();

int addNode(node_t *node, int val, const char lr);

int changeNode(node_t *node, int val);

void printNode(node_t node);

void printTree(tree_t);

int nodeDepth(node_t *node);

int treeDepth(tree_t tree);

int nodeEndNodeCount(node_t *node);

int endNodeCount(tree_t tree);

int nodeContainsN(node_t *node, int n);

int treeContainsN(tree_t tree, int n);

int nodeNodeCount(node_t *node);

int nodeCount(tree_t tree);

void putNodeInArray(node_t *node, int *array, int *i);

int putTreeInArray(tree_t tree, int *array);

void sortArray(int *array, int len);

void insertInNode(node_t *node, int *array, int *i);

void insertInTree(tree_t *tree, int *array);

void sortTree(tree_t *tree);
