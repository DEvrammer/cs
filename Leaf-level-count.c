#include <stdio.h>

#include <stdlib.h>

struct node {

  int data;

  struct node *left;

  struct node *right;

};

struct node *insert(struct node *root, int data) {

  if (root == NULL) {

    root = (struct node *)malloc(sizeof(struct node));

    root->data = data;

    root->left = NULL;

    root->right = NULL;

  } else if (data < root->data) {

    root->left = insert(root->left, data);

  } else {

    root->right = insert(root->right, data);

  }

  return root;

}

void display(struct node *root, int level) {

  if (root == NULL) {

    return;

  }

  for (int i = 0; i < level; i++) {

    printf("  ");

  }

  printf("%d\n", root->data);

  display(root->left, level + 1);

  display(root->right, level + 1);

}

int countNodesAtLevel(struct node *root, int level) {

  if (root == NULL) {

    return 0;

  }

  if (level == 1) {

    return 1;

  }

  return countNodesAtLevel(root->left, level - 1) + countNodesAtLevel(root->right, level - 1);

}

int main() {

  struct node *root = NULL;

  root = insert(root, 10);

  root = insert(root, 5);

  root = insert(root, 15);

  root = insert(root, 2);

  root = insert(root, 7);

  root = insert(root, 12);

  root = insert(root, 17);

  printf("Nodes at each level:\n");

  for (int i = 1; i <= 4; i++) {

    printf("Level %d: %d\n", i, countNodesAtLevel(root, i));

  }

  printf("\nNodes in the tree:\n");

  display(root, 1);

  return 0;

}

