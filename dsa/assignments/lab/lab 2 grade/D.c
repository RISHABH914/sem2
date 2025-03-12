#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct Node {
    int data;
    int cnt;
    struct Node* left;
    struct Node* right;
} node;

// Function to create a new Node
node* newNode(int x) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    temp->cnt=0;
    return temp;
}
int buses;
int dfs(node* root) {
    if (root == NULL) return 0;

    int leftPassengers = dfs(root->left);
    int rightPassengers = dfs(root->right);

    int totalPassengers = leftPassengers + rightPassengers + root->data;

    if (root->data != 1 && totalPassengers > 0) { // Root node does not need a bus
        buses++;
        return 0; // Bus takes all passengers in this subtree
    }

    return totalPassengers;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    int n;
    scanf("%d", &n);

    int parent[n];
    node* nodes[n];
buses=0;
    // Read parent array and initialize nodes
    int dat[n];
    for(int i=0;i<n;i++){
        scanf("%d",&dat[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(dat[i]);
    }
    for (int i = 0; i < n; i++) {
            if(parent[i]!=-1){
                parent[i]-=1;
            }
    }

    node* root = NULL;

    // Construct the binary tree
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // Root node
        } else {
            node* parentNode = nodes[parent[i]];
            if (parentNode->left) {
                parentNode->right = nodes[i];
            } else {
                parentNode->left = nodes[i];
            }
        }
    }
printf("%d\n",dfs(root));
return 0;
}