#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
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

int depth(node* root,int a){
    if(root==NULL){
        return -1;
    }
    if(root->data==a){
        return 0;
    }
    int left=depth(root->left,a);
    if(left!=-1){
        return 1+left;
    }
    int right=depth(root->right,a);
    if(right!=-1){
        return 1+right;
    }
    return -1;
}
node* lca(node* root,int a,int b){
    if(root==NULL || root->data==a || root->data==b){
        return root;
    }
    node* left=lca(root->left,a,b);
    node* right=lca(root->right,a,b);
    if(left && right){
        return root;
    }
    if(left){
        return left;
    }else{
        return right;
    }
}
int main(){
    int n,q;
    scanf("%d %d", &n,&q);

    int parent[n];
    node* nodes[n];

    // Read parent array and initialize nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
        nodes[i] = newNode(i+1);
    }

    node* root = NULL;

    // Construct the binary tree
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];  // Root node
        } else {
            node* parentNode = nodes[parent[i]-1];
            if (parentNode->left) {
                parentNode->right = nodes[i];
            } else {
                parentNode->left = nodes[i];
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        node* temp=lca(root,a,b);
        int d1=depth(temp,a);
        int d2=depth(temp,b);
        printf("%d\n",d1+d2);
    }
return 0;
}