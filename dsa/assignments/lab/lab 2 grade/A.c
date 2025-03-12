#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node{
    long long int data;
    long long int cnt;
    struct node* left;
    struct node* right;
}node;

node* insert(node* root,long long int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->cnt=1;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL){
        return temp;
    }
    node* t=root;
    node* prev=NULL;
    while(root){
        prev=root;
        if(root->data<data){
            root=root->right;
        }else if(root->data>data){
            root=root->left;
        }else{
            root->cnt++;
            return t;
        }
    }
    if(prev){
        if(prev->data<data){
            prev->right=temp;
        }else{
            prev->left=temp;
        }
    }
    return t;
}

void print(node* root){
    if(root==NULL){
        return;

    }
    print(root->left);
    printf("%lld ",root->data);
    print(root->right);
}
long long int count;

long long int find(node* root,long long int data){
    if(root==NULL){
        return 0;
    }
    if(root->data==data){
        count+=root->cnt;
        return 1;
    }
    if(root->data<data){
        return find(root->right,data);
    }else{
        return find(root->left,data);
    }
}
node* delete(node* root,long long int data){
    node * temp=root;
    while(root){
        if(root->data>data){
            root=root->left;
        }else if(root->data<data){
            root=root->right;
        }else{
            root->cnt--;
            return temp;
        }
    }
    return root;
}
int main(){
    long long int t;
    scanf("%lld",&t);
    while(t--){
        count=0;
        long long int n,target;
        scanf("%lld %lld",&n,&target);
        long long int arr[n];
        node* root=NULL;
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            root=insert(root,arr[i]);
        }
       // print(root);
        for(int i=0;i<n;i++){
           long long int hel = find(root,target-arr[i]);
            delete(root,arr[i]);
            
           if(target-arr[i]==arr[i]){
            count--;
        }
            
        }
        printf("%lld\n",count);
        count=0;
    }
return 0;
}