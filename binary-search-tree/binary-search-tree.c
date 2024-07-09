#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

typedef struct
{
  Node *root;
} BinarySearchTree;

// initialize dynamic memory Node
Node *nodeFactory(int value)
{
  Node *newNodePtr = (Node *)malloc(sizeof(Node));
  newNodePtr->data = value;
  newNodePtr->left = NULL;
  newNodePtr->right = NULL;

  return newNodePtr;
}

void insertOnTree(int value, Node **root)
{
  Node *newNode = nodeFactory(value);
  Node **currentPtP = root;

  while (*currentPtP != NULL)
  {
    if ((**currentPtP).data > value)
    {
      currentPtP = &(**currentPtP).left;
      continue;
    }
    else if ((**currentPtP).data < value)
    {
      currentPtP = &(**currentPtP).right;
      continue;
    }
    else
    {
      printf("Attempt to insert duplicate value.");
      return;
    }
  }

  *currentPtP = newNode;
}

void printNode(Node *node)
{
  Node *current = node;

  if (current->left != NULL)
  {
    printNode(current->left);
  }

  if (current->right != NULL)
  {
    printNode(current->right);
  }

  printf("%d ", current->data);
}

// clean dynamic memory nodes
void recursiveNodeCleaning(Node *node)
{
  Node *current = node;

  if (current->left != NULL)
  {
    recursiveNodeCleaning(current->left);
  }

  if (current->right != NULL)
  {
    recursiveNodeCleaning(current->right);
  }

  free(current);
  current = NULL;
}