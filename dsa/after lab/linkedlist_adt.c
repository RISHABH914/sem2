#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* root,int pos,int data){
    node* prev=NULL;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;

    if(pos==0){
        temp->next=root;
        return temp;
    }
    node* trav=root;
    while(pos!=0 && trav!=NULL){
        prev=trav;
        trav=trav->next;
        pos--;
    }
    if(pos!=0){
        return root;
    }
    prev->next=temp;
    temp->next=trav;
    return root;
}

node* delete(node* root,int pos){
    node* prev=NULL;
    if(root==NULL){
        return root;
    }
    if(pos==0){
        return root->next;
    }
    node* trav=root;
    while(pos!=0 && trav!=NULL){
        prev=trav;
        trav=trav->next;
        pos--;
    }
    if(pos!=0){
        return root;
    }
    if(trav==NULL){
        return root;
    }
    prev->next=trav->next;
    return root;
}

void print(node* root){
    while(root!=NULL){
        printf("%d ",root->data);
        root=root->next;
    }
    printf("\n");
}
int main(){
    int q;
    scanf("%d",&q);
    node* root=NULL;
    while(q--){

        int op,index;
        scanf("%d %d",&op,&index);
        if(op==0){
            int data;
            scanf("%d",&data);
            root=insert(root,index,data);
        }else{
            root=delete(root,index);
        }

        print(root);
    }
return 0;
}