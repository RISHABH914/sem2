#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void lonely(node* root, node* parent) {
    if (!root) return;
    lonely(root->left, root);
    if (parent == NULL || parent->left == NULL || parent->right == NULL) {
        printf("%d ", root->data);
    }
    lonely(root->right, root);
}

int main() {
    int n;
    scanf("%d", &n);
    int parent[n];
    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(i);
    }

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];
        } else {
            struct Node* parentNode = nodes[parent[i]];
            if (i<parent[i]) {
                parentNode->left = nodes[i];
            } else {
                parentNode->right = nodes[i];
            }
        }
    }

    lonely(root, NULL);
    return 0;
}
