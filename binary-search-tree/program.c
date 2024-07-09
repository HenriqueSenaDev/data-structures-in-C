#include <stdio.h>
#include "binary-search-tree.c"

int main()
{
  int items[20] = {
      56, 23, 87, 42, 9, 71, 34, 65, 15, 78, 3, 91, 50, 27, 68, 10, 84, 39, 62, 5};

  int treeSize = 20;

  BinarySearchTree tree;
  tree.root = NULL;

  for (int i = 0; i < treeSize; i++)
  {
    insertOnTree(items[i], &tree.root);
  }

  // printNode(tree.root);
  printf("\n");

  recursiveNodeCleaning(tree.root);

  return 0;
}