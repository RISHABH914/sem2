#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* insert_beg(node* root,int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=root;
    return temp;
}

node* insert_las(node* root,int data){
    
    node* org=root;
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(root==NULL){
        return temp;
    }
    while(org->next!=NULL){
        org=org->next;
    }
    org->next=temp;
    return root;
}

node* del_fir(node* root){
    printf("%d\n",root->data);
    return root->next;
}

node* del_las(node* root){
    node* temp=root;
    node* prev=root;
    if(root->next==NULL){
        printf("%d\n",root->data);
        return NULL;
    }
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    printf("%d\n",temp->data);
    return root;
}

void size(node* root){
    int cnt=0;
    while(root!=NULL){
        root=root->next;
        cnt++;
    }
    printf("%d\n",cnt);
}
int main(){
    int q;
    scanf("%d",&q);
    node* root=NULL;
    while(q--){
        int p,k;
        scanf("%d",&p);
        if(p==1){
            scanf("%d",&k);
            root=insert_beg(root,k);
            printf("%d\n",k);
        }else if(p==2){
            scanf("%d",&k);
            root=insert_las(root,k);
            printf("%d\n",k);
        }else if(p==3){
            if(root==NULL){
                printf("-1\n");
                continue;
            }
            root=del_fir(root);
        }else if(p==4){
            if(root==NULL){
                printf("-1\n");
                continue;
            }
            root=del_las(root);

        }else {
            size(root);
        }
    }
return 0;
}