#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
    int count;
} tree;

tree* constructBST(int postorder[], int* postIndex, int key, int min, int max, int size) {
    if (*postIndex < 0)
        return NULL;

    tree* root = NULL;

    if (key > min && key < max) {
        root = (tree*)malloc(sizeof(tree));
        root->data = key;
        root->left = root->right = NULL;
        root->count = 1;
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0) {
            root->right = constructBST(postorder, postIndex, postorder[*postIndex], key, max, size);
            root->left = constructBST(postorder, postIndex, postorder[*postIndex], min, key, size);
        }
    }
    return root;
}

void update_counts(tree* root) {
    if (!root) return;
    update_counts(root->left);
    update_counts(root->right);
    root->count = 1;
    if (root->left) root->count += root->left->count;
    if (root->right) root->count += root->right->count;
}

void count_unbalanced(tree* root, int* count) {
    if (!root) return;
    int left = root->left ? root->left->count : 0;
    int right = root->right ? root->right->count : 0;
    if (abs(left - right) > 1) (*count)++;
    count_unbalanced(root->left, count);
    count_unbalanced(root->right, count);
}

void free_tree(tree* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int postIndex = n - 1;
    tree* root = constructBST(arr, &postIndex, arr[postIndex], INT_MIN, INT_MAX, n);

    update_counts(root);
    int unbalanced = 0;
    count_unbalanced(root, &unbalanced);
    printf("%d\n", unbalanced);

    free_tree(root);
    return 0;
}