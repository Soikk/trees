#include "trees.h"


node_t* createNode(int val){
  node_t *newNode = malloc(sizeof(node_t));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
tree_t* createTree(){
  tree_t *newTree = malloc(sizeof(tree_t));

  newTree->root = createNode(0);
  return newTree;
}

int addNode(node_t *node, int val, const char lr){
  if(lr == 'l'){
    node->left = createNode(val);
  }else if(lr == 'r'){
    node->right = createNode(val);
  }else{
    return -1;
  }
  return 0;
}

int changeNode(node_t *node, int val){
  if(node){
    node->val = val;
    return 0;
  }
  return -1;
}

void printNode(node_t node){
  printf("( %d ", node.val);
  if(node.left != NULL){
    printf("L");
    printNode(*node.left);
  }
  if(node.right != NULL){
    printf("R");
    printNode(*node.right);
  }
  printf(") ");
}

void printTree(tree_t tree){
  printNode(*tree.root);
}

int nodeDepth(node_t *node){
  int t = 0;
  if(node){
      int l = nodeDepth(node->left);
      int r = nodeDepth(node->right);
    t = 1 + ((l>r)?l:r);
  }
  return t;
}
int treeDepth(tree_t tree){
  return nodeDepth(tree.root);
}

int nodeEndNodeCount(node_t *node){
  int t = 0, l = 0, r = 0;
  if(node){
    if(!node->left && !node->right)
      return 1;
    else{
	l = nodeEndNodeCount(node->left);
	r = nodeEndNodeCount(node->right);
    }
    t = l + r;
  }
  return t;
}

int endNodeCount(tree_t tree){
  return nodeEndNodeCount(tree.root);
}

int nodeContainsN(node_t *node, int n){
  if(node){
    if(node->val == n)
      return 1;
    else
      return nodeContainsN(node->left, n) + nodeContainsN(node->right, n);
  }
  return 0;
}

int treeContainsN(tree_t tree, int n){
  return nodeContainsN(tree.root, n);
}

int nodeNodeCount(node_t *node){
  int t = 0;
  if(node)
    t = 1 + nodeNodeCount(node->left) + nodeNodeCount(node->right);
  return t;
}

int nodeCount(tree_t tree){
  return nodeNodeCount(tree.root);
}

void putNodeInArray(node_t *node, int *array, int *i){
  if(node){
    array = realloc(array, ((*i)+1)*sizeof(int));
    array[*i] = node->val;
    (*i)++;
    putNodeInArray(node->left, array, i);
    putNodeInArray(node->right, array, i);
  }
}
int putTreeInArray(tree_t tree, int *array){
  int i = 0;
  putNodeInArray(tree.root, array, &i);
  return i;
}

void sortArray(int *array, int len){
  int sorted = 0;
  while(!sorted){
    int changes = 0;
    for(int i = 0; i < len-1; i++){
      if(array[i] > array[i+1]){
	changes++;
	array[i] += array[i+1];
	array[i+1] = array[i] - array[i+1];
	array[i] -= array[i+1];
      }
    }
    if(!changes)
      sorted = 1;
  }
}

void insertInNode(node_t *node, int *array, int *i){
  if(node->left)
    insertInNode(node->left, array, i);
  node->val = array[*i];
  *i += 1;
  if(node->right)
    insertInNode(node->right, array, i);
}

void insertInTree(tree_t *tree, int *array){
  int i = 0;
  insertInNode(tree->root, array, &i);
}

void sortTree(tree_t *tree){
  int *numbers = malloc(1*sizeof(int));
  int t = putTreeInArray(*tree, numbers);
  sortArray(numbers, t);
  insertInTree(tree, numbers);
  
}
