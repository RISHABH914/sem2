#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
    int leftcnt;
    int rightcnt;

}node;

node* insert(node *root,int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    temp->leftcnt=0;
    temp->rightcnt=0;
    if(root==NULL){
        return temp;
    }
    node* prev=NULL;
    node* store=root;
    while(root!=NULL){
        prev=root;
        if(root->data<data){
            root->rightcnt++;
            root=root->right;
        }else{
            root->leftcnt++;
            root=root->left;
        }
    }
    if(prev->data<data){
        prev->right=temp;
    }else{
        prev->left=temp;
    }
    return store;
}

void left(node* root,int data){
    while(root!=NULL){
        if(root->data==data){
            printf("%d\n",root->leftcnt);
            return ;
        }else if(root->data<data){
            root=root->right;
        }else{
            root=root->left;
        }
    }
}

void right(node* root,int data){
    while(root!=NULL){
        if(root->data==data){
            printf("%d\n",root->rightcnt);
            return ;
        }else if(root->data<data){
            root=root->right;
        }else{
            root=root->left;
        }
    }
}
int main(){
    int n,q;
    node* root=NULL;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        root=insert(root,data);
    }

    while(q--){
        int op,data;
        scanf("%d %d",&op,&data);
        if(op==1){
            root=insert(root,data);
        }else if(op==2){
            left(root,data);
        }else if(op==3){
            right(root,data);
        }
    }

return 0;
}