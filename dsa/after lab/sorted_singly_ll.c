#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    long long int data;
    struct node* next;
} node;

node* make(long long int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node* insert(node* root,long long int data) {
    node* temp = make(data);

    if (root == NULL || root->data >= data) {
        temp->next = root;
        return temp;  // New head
    }

    node* prev = NULL;
    node* trav = root;
    while (trav != NULL && trav->data < data) {
        prev = trav;
        trav = trav->next;
    }

    prev->next = temp;
    temp->next = trav;
    return root;
}

node* delete(node* root,long long int data) {
    if (root == NULL) return NULL; // Prevents segmentation fault

    if (root->data == data) {  // Deleting head
        node* temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    node* prev = NULL;
    node* trav = root;
    while (trav != NULL && trav->data < data) {
        prev = trav;
        trav = trav->next;
    }
    if (trav == NULL || trav->data != data) return root;  // Not found

    prev->next = trav->next;
    free(trav);
    return root;
}

void print(node* root) {
    while (root != NULL) {
        printf("%lld ", root->data);
        root = root->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;

    if (n > 0) {
        long long int num;
        scanf("%lld", &num);
        root = make(num);

        node* trav = root;
        for (int i = 1; i < n; i++) {
            scanf("%lld", &num);
            node* temp = make(num);
            trav->next = temp;
            trav = trav->next;
        }
    }

    long long int q;
    scanf("%lld", &q);
    while (q--) {
        long long int op;
        scanf("%lld", &op);
        if (op == 3) {
            if (root == NULL) printf("\n");
            else print(root);
        } else if (op == 1) {
            long long int d;
            scanf("%lld", &d);
            root = insert(root, d);
        } else if (op == 2) {
            long long int d;
            scanf("%lld", &d);
            root = delete(root, d);
        }
    }

    return 0;
}
