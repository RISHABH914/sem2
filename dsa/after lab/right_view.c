#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newnode(int i) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = i;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

void rightview(node* root, int level, int* maxlevel) {
    if (root == NULL) {
        return;
    }
    if (level > *maxlevel) {
        // Ensure res array has enough space
        
        printf("%d ",root->data);
        *maxlevel = level;
    }

    // Traverse right subtree first
    rightview(root->right, level + 1, maxlevel);
    rightview(root->left, level + 1, maxlevel);
}

int main() {
    int n;
    scanf("%d", &n);
    node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = newnode(i);
    }

    int parent[n];
    node* root = NULL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        if (parent[i] == -1) {
            root = nodes[i];
        } else {
            node* parentnode = nodes[parent[i]];
            if (parentnode->left == NULL) {
                parentnode->left = nodes[i];
            } else {
                parentnode->right = nodes[i];
            }
        }
    }

    int maxlevel = -1;
    int index = 0;

    rightview(root,0,&maxlevel);

    return 0;
}
