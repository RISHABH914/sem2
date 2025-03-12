#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
int *mindat;
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}node;

node* createnode(int i){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=i;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

node* find(node* root,int i){
    if(root->data==i){
        return root;
    }
    if(root->data<i){
        return find(root->right,i);
    }
    return find(root->right,i);
}

int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
int minintree(node* root){
    if(root==NULL){
        return INT_MAX;
    }

    if(mindat[root->data]!=-1){
        return mindat[root->data];
    }
    int left=minintree(root->left);
    int right=minintree(root->right);
    int one=min(left,right);
    mindat[root->data]=min(one,root->data);
    return mindat[root->data];
}
int main(){
    int n;
    scanf("%d",&n);
    node* nodes[n];
    for(int i=0;i<n;i++){
        nodes[i]=createnode(i);
    }
    node* root=NULL;
    for(int i=0;i<n;i++){
        int parent;
        scanf("%d",&parent);
        if(parent==-1){
            root=nodes[i];
        }else{
            node* parentnode=nodes[parent];
            if(parentnode->left==NULL){
                parentnode->left=nodes[i];
            }else{
                parentnode->right=nodes[i];
            }
            
        }
    }
    mindat=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        mindat[i]=-1;
    }
    for(int i=0;i<n;i++){
        
        printf("%d ",minintree(nodes[i]));
    }
return 0;
}