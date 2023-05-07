#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height > right_height) {
        return left_height + 1;
    }
    else {
        return right_height + 1;
    }
}


void print_level(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    }
    else if (level > 1) {
        print_level(root->left, level-1);
        print_level(root->right, level-1);
    }
}


void display_levels(Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
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

    
    printf("\nNodes at each level of the Binary Search Tree:\n");
    display_levels(root);

    
    printf("\nTotal levels in the Binary Search Tree: %d\n", height(root));

    return 0;
}
