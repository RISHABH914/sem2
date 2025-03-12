#include <stdlib.h>
#include <assert.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
  
// structure of the tree node
typedef struct choco{
    int left;
    int right;
    int size;
}choco;

typedef struct node {
    choco data;
    struct node* left;
    struct node* right;
    int ht;
}node;
  
// function prototyping
struct node* create(choco); // Creates a new tree node with the given data and returns it
struct node* insert(struct node*, choco); // Inserts a new node in the AVL tree and returns the root of the tree
struct node* delete(struct node*, choco); // Deletes *one* occurrence of the given data from the AVL tree, does nothing if the data is not found and returns the root of the tree
struct node* search(struct node*, choco); // Searches for the given data in the AVL tree, returns the node if found, NULL otherwise
struct node* rotate_left(struct node*); // Rotates the tree rooted at the given node to the left and returns the new root
struct node* rotate_right(struct node*); // Rotates the tree rooted at the given node to the right and returns the new root
int balance_factor(struct node*); // returns the balance factor of the given node
int height(struct node*); // returns the height of the given node
  
struct node* create(choco data) {
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
 }
  
struct node* rotate_left(struct node* root) {
    struct node* right_child = root->right;
    root->right = right_child->left;
    right_child->left = root;
  
    // update the heights of the nodes
    root->ht = height(root);
    right_child->ht = height(right_child);
  
    // return the new node after rotation
    return right_child;
}
  
struct node* rotate_right(struct node* root) {
    struct node* left_child = root->left;
    root->left = left_child->right;
    left_child->right = root;
  
    // update the heights of the nodes
    root->ht = height(root);
    left_child->ht = height(left_child);
  
    // return the new node after rotation
    return left_child;
}
 
int balance_factor(struct node* root) {
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
    return lh - rh;
}
  
int height(struct node* root) {
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
  
struct node* insert(struct node* root, choco data) {
    if (root == NULL) {
        struct node* new_node = create(data);
        if (new_node == NULL) {
            return NULL;
        }
        root = new_node;
    } else if (data.left < root->data.left) {
        // Insert into left subtree
        root->left = insert(root->left, data);
 
        // Balance the tree
        if (balance_factor(root) == 2) {
            if (data.left < root->left->data.left) {
                root = rotate_right(root);
            } else {
                root->left = rotate_left(root->left);
                root = rotate_right(root);
            }
        }
    } else {
        // Insert into right subtree
        root->right = insert(root->right, data);
 
        // Balance the tree
        if (balance_factor(root) == -2) {
            if (data.left >= root->right->data.left) {
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
  
struct node* delete(struct node* root, choco x) {
    if (root == NULL) {
        return NULL;
    }
 
    if (x.left < root->data.left) {
        root->left = delete(root->left, x);
    } else if (x.left > root->data.left) {
        root->right = delete(root->right, x);
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
        }
    }
 
    // Update height
    root->ht = height(root);
 
    // Balance the tree
    int bf = balance_factor(root);
 
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
  
struct node* search(struct node* root, choco key) {
    if (root == NULL) {
        return root;
    }
  
    if (root->data.left == key.left) {
        return root;
    }
  
    if (key.left > root->data.left) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    } 
}

void sort(choco res[],int *index,node* root){
    if(root==NULL){
        return;
    }
    sort(res,index,root->left);
    res[*index]=root->data;
    (*index)++;
    sort(res,index,root->right);
}

void sift_up(choco arr[],int n,int index){
    if(index>=n){
        return ;
    }
    if(index<0){
        return;
    }
    int parent=(index-1)/2;
    if(arr[parent].size>arr[index].size || (arr[parent].size==arr[index].size && arr[parent].left>arr[index].left)){
        choco temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=temp;
        sift_up(arr,n,parent);
    }
}

void insert_heap(choco arr[],int *size,choco data){
    arr[*size]=data;
    (*size)++;
    sift_up(arr,*size,(*size)-1);
}

void sift_down(choco arr[],int n,int index){
    int child1=2*index +1;
    int child2=2*index +2;
    int smallest=index;
    if(arr[child1].size<arr[smallest].size || (arr[child1].size==arr[smallest].size && arr[child1].left<arr[index].left)){
        smallest=child1;
    }
    if(arr[child2].size<arr[smallest].size || (arr[child2].size==arr[smallest].size && arr[child2].left<arr[index].left)){
        smallest=child2;
    }
    if(index!=smallest){ 
        choco temp=arr[smallest];
        arr[smallest]=arr[index];
        arr[index]=temp;
        sift_down(arr,n,smallest);
    }
}
void heapify(choco arr[],int n){
    for(int i=(n-1)/2;i>=0;i--){
        sift_down(arr,n,i);
    }
}
void delete_heap(choco arr[],int* size){
    arr[0]=arr[*size -1];
    (*size)--;
    sift_down(arr,*size,0);
}
int main(){
    int n;
    scanf("%d",&n);
    node* root=NULL;
        choco data[n];
        int temp=0;
        for(int i=0;i<n;i++){
            int start,end;
            scanf("%d %d",&start,&end);
            data[i].left=start;
            data[i].right=end;
            data[i].size=end-start;
            root=insert(root,data[i]);
        }
        choco sorted[n];
        int size=0;
        sort(sorted,&size,root);
        heapify(sorted,n);
        for(int i=0;i<n;i++){
            printf("%d ",sorted[i].size);
        }
        printf("\n");
        int k;
        scanf("%d",&k);
        int queries[k];
        for(int i=0;i<k;i++){
            scanf("%d",&queries[i]);
            while(size!=0 && sorted[0].right<queries[i]){
                delete_heap(sorted,&size);
            }
            int j=0;
            while(j<size){
                if(sorted[j].left<queries[i])
            }
        }



}