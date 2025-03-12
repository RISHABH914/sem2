#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* insertSorted(node* root, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (root == NULL || root->data >= data) { 
        temp->next = root;
        return temp; // New head
    }

    node* current = root;
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
    return root;
}

void print(node* root) {
    if (root == NULL) {
        printf("Empty List\n");
        return;
    }
    while (root) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

node* deleteNode(node* root, int data) {
    if (root == NULL) return NULL;

    node* temp = root;
    node* prev = NULL;

    // If the head itself needs to be deleted
    if (root->data == data) {
        root = root->next;
        free(temp);
        return root;
    }

    // Search for the node to delete
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == NULL) return root;

    // Unlink and free memory
    prev->next = temp->next;
    free(temp);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    node* root = NULL;

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        root = insertSorted(root, temp); // Directly inserting in sorted order
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {  // Insert operation
            int data;
            scanf("%d", &data);
            root = insertSorted(root, data);
        } else if (op == 2) {  // Delete operation
            int temp;
            scanf("%d", &temp);
            root = deleteNode(root, temp);
        }else if(op==3){
        print(root); // Print after each operation
        }
    }

    return 0;
}
