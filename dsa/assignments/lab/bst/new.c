#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* insert(node* root,int data){
    node* trav=root;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL){
        return temp;
    }
    node* prev=NULL;
    while(trav!=NULL){
        prev=trav;
        if(trav->data<data){
            trav=trav->right;
        }else{
            trav=trav->left;
        }
    }
    if(prev->data<data){
        prev->right=temp;
    }else{
        prev->left=temp;
    }
    return root;
}

node* delete(node* root,int data){
    if(root==NULL){
        return root;
    }
    node* temp=root;
    node* prev=NULL;
    while(temp!=NULL){
        
        if(temp->data<data){
            temp=temp->right;
        }else if(temp->data>data){
            temp=temp->left;
        }else{
            if(temp->right==NULL){
                if(prev!=NULL){
                    if(temp==prev->right){
                        prev->right=temp->left;
                        break;
                    }else{
                        prev->left=temp->left;
                        break;
                    }
                }else{
                    return temp->left;
                }
            }else if(temp->left==NULL){
                if(prev!=NULL){
                    if(temp==prev->right){
                        prev->right=temp->right;
                        break;
                    }else{
                        prev->left=temp->right;
                        break;
                    }
                }else{
                    return temp->right;
                }
            }else{
                node* another=temp->right;
                node* prev1=temp;
                while(another->left!=NULL){
                    prev1=another;
                    another=another->left;
                }
                prev1->left=another->right;
                temp->data=another->data;
                break;
            }
        }
        prev=temp;
    }
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        root=insert(root,arr[i]);
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a;
        scanf("%d",&a);
        root=delete(root,a);
        print(root);
    }
return 0;
}