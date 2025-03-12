#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

// Function to create a new Node
node* newNode(int x) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert into BST
node* insert(node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to find lonely nodes in inorder order
void findLonelyNodes(node* root, int isLonely) {
    if (!root) return;

    // Inorder traversal (Left, Node, Right)
    findLonelyNodes(root->left, root->right == NULL); // Left subtree

    // Print the node if it's lonely (either root or no sibling)
    if (isLonely || root->left == NULL || root->right == NULL) {
        printf("%d ", root->data);
    }

    findLonelyNodes(root->right, root->left == NULL); // Right subtree
}

int main() {
    int n;
scanf("%d", &n);  // Read the number of nodes

int parent[n];
struct Node* nodes[n];  // Array to store all nodes

// Read the parent array
for (int i = 0; i < n; i++) {
    scanf("%d", &parent[i]);
    nodes[i] = newNode(i);  // Create a node for each index
}

struct Node* root = NULL;

// Construct the binary tree from the parent array
for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
        root = nodes[i];  // Root node has no parent
    } else {
        struct Node* parentNode = nodes[parent[i]-1];
        if ((i+1)<parent[i]) {
            parentNode->left = nodes[i];  // Assign left child
        } else  {
            parentNode->right = nodes[i];  // Assign right child
        }
    }
}

    findLonelyNodes(root, 1); // Root is always lonely
    printf("\n");
    return 0;
}
