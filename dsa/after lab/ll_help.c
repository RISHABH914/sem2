#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;

}node;

node* atbegin(node* root,int data){
    printf("%d\n",data);
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=root;
    return temp;
}

node* atlast(node* root,int data){
    printf("%d\n",data);
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(root==NULL){
        return temp;
    }
    node* trav=root;
    node* prev=NULL;
    while(trav!=NULL){
        prev=trav;
        trav=trav->next;

    }
    prev->next=temp;
    return root;
}

node* deletefirst(node* root){
    if(root==NULL){
        printf("-1\n");
        return root;
    }
    printf("%d\n",root->data);
    return (root->next);
}

node* deletelast(node* root){
    if(root==NULL){
        printf("-1\n");
        return root;
    }

    node* prev=NULL;
    node* trav=root;
    while(trav->next!=NULL){
        prev=trav;
        trav=trav->next;
    }
printf("%d\n",trav->data);
if(prev==NULL){
    return NULL;
}
    prev->next=NULL;
    return root;
}


void size(node* root){
    int cnt=0;
    while(root!=NULL){
        cnt++;
        root=root->next;

    }
    printf("%d\n",cnt);
}
int main(){
    
    node* root=NULL;
    int t;
    scanf("%d",&t);
    while(t--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int data;
            scanf("%d",&data);
            root=atbegin(root,data);
        }else if(op==2){
            int data;
            scanf("%d",&data);
            root=atlast(root,data);
        }else if(op==3){
            root=deletefirst(root);
        }else if(op==4){
            root=deletelast(root);
        }else if(op==5){
            size(root);
        }
    }
return 0;
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