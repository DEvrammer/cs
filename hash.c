#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    if (table[index] == 0) { 
        table[index] = key;
    } else { 
        int i = (index + 1) % TABLE_SIZE;
        while (i != index && table[i] != 0) {
            i = (i + 1) % TABLE_SIZE;
        }
        if (i == index) {
            printf("Hash table is full, cannot insert %d\n", key);
        } else {
            table[i] = key;
        }
    }
}

void delete(int table[], int key) {
    int index = hash(key);
    if (table[index] == key) { 
        table[index] = 0;
    } else { 
        int i = (index + 1) % TABLE_SIZE;
        while (i != index && table[i] != key) {
            i = (i + 1) % TABLE_SIZE;
        }
        if (i == index) {
            printf("Key %d not found in hash table\n", key);
        } else {
            table[i] = 0;
        }
    }
}

void display(int table[]) {
    printf("Hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, table[i]);
    }
}

int main() {
    int table[TABLE_SIZE] = {0};
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a key\n");
        printf("2. Delete a key\n");
        printf("3. Display the hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to be inserted: ");
                scanf("%d", &key);
                insert(table, key);
                break;
            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                delete(table, key);
                break;
            case 3:
                display(table);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
