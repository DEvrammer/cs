#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main() {
    Node* root = NULL;

    int choice, data,x;
    while (1) {
        printf("1. Create a new Binary Search Tree\n"
               "2. Insert a node into the Binary Search Tree\n"
               "3. Traverse the Binary Search Tree in pre-order\n"
               "4. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL;
                printf("Binary Search Tree created.\n");
                break;
            case 2:
                do{
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted into the Binary Search Tree.\n", data);
          
                printf("\n Do you want to insert more data (1/0): ");
                scanf("%d",&x);
            }while(x!=0);
            case 3:
                printf("Pre-order traversal of the Binary Search Tree: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
