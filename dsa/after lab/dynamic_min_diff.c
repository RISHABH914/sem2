#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<limits.h>
typedef struct node {
    int data;
    struct node* right;
    struct node* left;
} node;

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Insert node in BST
node* insert(node* root, int data,int* mindif) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;

    if (root == NULL) {
        return temp;
    }

    node* trav = root;
    node* prev = NULL;
    
    while (trav != NULL) {
        prev = trav;
        *mindif=min(*mindif,abs(trav->data -data));
        if (trav->data < data) {
            trav = trav->right;
        } else {
            trav = trav->left;
        }
    }
    
    if (prev->data < data) {
        prev->right = temp;
    } else {
        prev->left = temp;
    }

    return root;
}


node* successor(node* root) {
    if (root == NULL || root->right == NULL) return NULL;
    node* temp = root->right;
    while (temp->left) {
        temp = temp->left;
    }
    return temp;
}


node* predecessor(node* root) {
    if (root == NULL || root->left == NULL) return NULL;
    node* temp = root->left;
    while (temp->right) {
        temp = temp->right;
    }
    return temp;
}

int mindiff(node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return -1;
    }

    int mindif = __INT_MAX__;
    node* temp = successor(root);
    if (temp) {
        mindif = abs(root->data - temp->data);
    }

    temp = predecessor(root);
    if (temp) {
        mindif = min(mindif, abs(root->data - temp->data));
    }

    if (root->left) {
        int left = mindiff(root->left);
        if (left != -1) {
            mindif = min(mindif, left);
        }
    }

    if (root->right) {
        int right = mindiff(root->right);
        if (right != -1) {
            mindif = min(mindif, right);
        }
    }

    return mindif;
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int mindif=INT_MAX;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        root = insert(root, temp,&mindif);
        if(i==0){
            printf("-1 ");
            continue;
        }
        printf("%d ",mindif);
    }

    return 0;
}
