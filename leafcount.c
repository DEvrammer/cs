#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


int count_nodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}


int count_leaf_nodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    else {
        return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
    }
}

int main() {
    Node* root = NULL;

    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Binary Search Tree created.\n");

    printf("\nTotal number of nodes in the Binary Search Tree: %d\n", count_nodes(root));

    
    printf("\nTotal number of leaf nodes in the Binary Search Tree: %d\n", count_leaf_nodes(root));

    return 0;
}
