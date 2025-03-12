#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* root,int index,int data){
    node* temp=root;
    node* another=(node*)malloc(sizeof(node));
    another->data=data;
    if(index==0){
        another->next=root;
        return another;
    }
    for(int i=0;i<index-1;i++){
        if(temp==NULL){
            return root;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        return root;
    }
    another->next=temp->next;
    temp->next=another;
    return root;
}

node* delete(node* root,int index){
    if(root==NULL){
        return root;
    }
    if(index==0){
        return root->next;
    }
    node* temp=root;
    node* prev=root;
    for(int i=0;i<index;i++){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return root;
    }else{
        prev->next=temp->next;
    }
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
        int a;
        scanf("%d",&a);
        if(a==0){
            int b,c;
            scanf("%d %d",&b,&c);
            root=insert(root,b,c);
        }else{
            int c;
            scanf("%d",&c);
            root=delete(root,c);
        }

        print(root);
    }
return 0;
}