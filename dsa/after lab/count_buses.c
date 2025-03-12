#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int id;
    bool hasPassenger;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* nodes[1000002];
TreeNode* root = NULL;

TreeNode* createNode(int id, bool hasPassenger) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->id = id;
    newNode->hasPassenger = hasPassenger;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int parent, int child) {
    if (!nodes[parent]) return;
    if (!nodes[parent]->left) nodes[parent]->left = nodes[child];
    else nodes[parent]->right = nodes[child];
}

int countBuses(TreeNode* root, int* buses,TreeNode* parent) {
    if (root == NULL) return 0;
    
    int leftPassengers = countBuses(root->left, buses,parent);
    int rightPassengers = countBuses(root->right, buses,parent);
    
    int totalPassengers = leftPassengers + rightPassengers + (root->hasPassenger ? 1 : 0);
    if(root==parent){
        return totalPassengers;
    }
    if(leftPassengers==0 && rightPassengers==0){
        (*buses)+=(root->hasPassenger);
    }
    return totalPassengers;
}

void freetree(TreeNode* root){
    if(root==NULL){
        return;
    }
    freetree(root->right);
    freetree(root->left);
    free(root);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i, false);
    }
    
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);
        nodes[i]->hasPassenger = p;
    }
    
    for (int i = 1; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        if (parent == -1) root = nodes[i];
        else insert(parent, i);
    }
    
    int buses = 0;
    countBuses(root, &buses,root);
    printf("%d\n", buses);
    freetree(root);
    return 0;
}
