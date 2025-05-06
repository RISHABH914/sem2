#include <stdlib.h>
#include <assert.h>
#include<stdio.h>
// structure of the tree node

//correctly updating the countofnodes and sum of the avl tree
typedef struct node {
    long long int data;
    struct node* left;
    struct node* right;
    long long int ht;
    long long int sum;
    long long int countofnodes;
}node;
  
// function prototyping
struct node* create(long long int); // Creates a new tree node with the given data and returns it
struct node* insert(struct node*,long long int); // Inserts a new node in the AVL tree and returns the root of the tree
struct node* delete(struct node*,long long int); // Deletes *one* occurrence of the given data from the AVL tree, does nothing if the data is not found and returns the root of the tree
struct node* search(struct node*,long long int); // Searches for the given data in the AVL tree, returns the node if found, NULL otherwise
struct node* rotate_left(struct node*); // Rotates the tree rooted at the given node to the left and returns the new root
struct node* rotate_right(struct node*); // Rotates the tree rooted at the given node to the right and returns the new root
long long int balance_factor(struct node*); // returns the balance factor of the given node
long long int height(struct node*); // returns the height of the given node
  
struct node* create(long long int data) {
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->countofnodes=1;
    new_node->sum=data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
 }
 void getsum(node* root){
    if(root==NULL){
        return;
    }
    root->countofnodes=1;
    if(root->right){
        root->countofnodes+=root->right->countofnodes;
    }
    if(root->left){
        root->countofnodes+=root->left->countofnodes;
    }

    root->sum=root->data;
    if(root->right){
        root->sum+=root->right->sum;
    }
    if(root->left){
        root->sum+=root->left->sum;
    }
  }
struct node* rotate_left(struct node* root) {
    node* a=root;
    node* b=root->left;
    node* c=root->right;
    node* d=c->right;
    node* e=c->left;

    a->right=e;
    getsum(a);
    c->left=a;
    getsum(c);
  
    // update the heights of the nodes
    root->ht = height(root);
    c->ht = height(c);
  
    // return the new node after rotation
    return c;
}
  
struct node* rotate_right(struct node* root) {
    node* a=root;
    node* b=root->left;
    node* c=b->left;
    node* d=b->right;
    node* e=a->right;
    a->left=d;
    getsum(a);
    b->right=a;
    getsum(b);
  
    // update the heights of the nodes
    a->ht = height(root);
    b->ht = height(b);
  
    // return the new node after rotation
    return b;
}
 
long long int balance_factor(struct node* root) {
    long long int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh - rh;
}
  
long long int height(struct node* root) {
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if (root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}
  
struct node* insert(struct node* root,long long int data) {
    if (root == NULL) {
        struct node* new_node = create(data);
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data < root->data) {
        // Insert into left subtree
        root->left = insert(root->left, data);
        root->countofnodes+=1;
        root->sum+=data;
 
        // Balance the tree
        if (balance_factor(root) == 2) {
            if (data < root->left->data) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    } else {
        // Insert into right subtree
        root->right = insert(root->right, data);
        root->countofnodes+=1;
        root->sum+=data;
        // Balance the tree
        if (balance_factor(root) == -2) {
            if (data >= root->right->data) {
                root = rotate_left(root);
            } else {
                root->right = rotate_right(root->right);
                root = rotate_left(root);
            }
        }
    }
 
    // Update height
    root->ht = height(root);
    return root;
}
  
struct node* delete(struct node* root,long long int x) {
    if (root == NULL) {
        return NULL;
    }
 
    if (x < root->data) {
        root->left = delete(root->left, x);
        root->countofnodes-=1;
        root->sum-=x;
    } else if (x > root->data) {
        root->right = delete(root->right, x);
        root->countofnodes-=1;
        root->sum-=x;
    } else { // Found the node to delete
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Find successor (smallest value in right subtree)
            struct node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
 
            // Replace data with successor value
            root->data = temp->data;
            // Delete the duplicate node from the right subtree
            root->right = delete(root->right, temp->data);
            
            getsum(root);
        }
    }
 
    // Update height
    root->ht = height(root);
 
    // Balance the tree
    long long int bf = balance_factor(root);
 
    if (bf == 2) {
        if (balance_factor(root->left) >= 0) {
            root = rotate_right(root);
        } else {
            root->left = rotate_left(root->left);
            root = rotate_right(root);
        }
    } else if (bf == -2) {
        if (balance_factor(root->right) <= 0) {
            root = rotate_left(root);
        } else {
            root->right = rotate_right(root->right);
            root = rotate_left(root);
        }
    }
 
    return root;
}
  
struct node* search(struct node* root,long long int key) {
    if (root == NULL) {
        return root;
    }
  
    if (root->data == key) {
        return root;
    }
  
    if (key > root->data) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    } 
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%lld %lld %lld\n",root->data,root->sum,root->countofnodes);
    inorder(root->right);
}

void findmin(node* root,long long int k,long long int* currcount,long long int *sum){
        if(*currcount>=k){
            return;

        }

        if(root==NULL){
            return;
        }
        if(root->left && root->left->countofnodes>k-(*currcount)){
            findmin(root->left,k,currcount,sum);
        }
        if(!root->left){
            (*currcount)++;
            (*sum)+=root->data;
            findmin(root->right,k,currcount,sum);
        }
        if(root->left && root->left->countofnodes<=k-(*currcount)){
            (*sum)+=root->left->sum;
            (*currcount)+=root->left->countofnodes;
            if(*currcount<k){
                (*currcount)++;
                (*sum)+=root->data;
                findmin(root->right,k,currcount,sum);
            }
        }
}
int main(){
    long long int n,k;
    scanf("%lld %lld",&n,&k);
    long long int arr[n];
    node* root=NULL;
    for(int i=0;i<n;i++){
        long long int data;
        scanf("%lld",&data);
        root=insert(root,data);
    }
    //inorder(root);

    long long int q;
    scanf("%lld",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            //insert
            long long int data;
            scanf("%lld",&data);
            root=insert(root,data);
            long long int sum=0;
            long long int currcount=0;
            findmin(root,k,&currcount,&sum);
                printf("%lld\n",sum);
            
        }else if(op==2){
            //delete
            long long int data;
            scanf("%lld",&data);
            root=delete(root,data);
            long long int sum=0;
           long long int currcount=0;
            findmin(root,k,&currcount,&sum);
                printf("%lld\n",sum);
            
        }else if(op==3){
            //update
            long long int x,y;
            scanf("%lld %lld",&x,&y);
            root=delete(root,x);
            root=insert(root,y);
            long long int sum=0;
            long long int currcount=0;
            findmin(root,k,&currcount,&sum);
                printf("%lld\n",sum);
            
        }
    }
}