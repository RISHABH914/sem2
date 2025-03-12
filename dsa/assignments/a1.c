#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    int attack;
    int defense;
    int cnt;
    int ncnt;
    struct node* right;
    struct node* left;
} node;

int cmp(int a1, int d1, int a2, int d2) {
    int sum1 = a1 + d1;
    int sum2 = a2 + d2;
    if (sum1 > sum2) return 1;
    if (sum1 < sum2) return -1;
    if (a1 > a2) return 1;
    if (a1 < a2) return -1;
    return 0;
}

node* insert(node* root, int attack, int defense) {
    if (root == NULL) {
        node* temp = (node*)malloc(sizeof(node));
        temp->attack = attack;
        temp->defense = defense;
        temp->cnt = 1;
        temp->ncnt = 1;
        temp->left = temp->right = NULL;
        return temp;
    }

    int com = cmp(root->attack, root->defense, attack, defense);
    if (com < 0) {
        root->left = insert(root->left, attack, defense);
        root->ncnt++;
    } else if (com > 0) {
        root->right = insert(root->right, attack, defense);
        root->ncnt++;
    } else {
        root->cnt++;
        root->ncnt++;
    }
    return root;
}

node* ispresent(int attack, int defense, node* root) {
    while (root != NULL) {
        int com = cmp(root->attack, root->defense, attack, defense);
        if (com < 0) root = root->left;
        else if (com > 0) root = root->right;
        else return root;
    }
    return NULL;
}

// Helper function to find a node and track the path
node* find_with_path(int attack, int defense, node* root) {
    /**path_len = 0;*/
    node* current = root;
    
    while (current != NULL) {
       /* path[*path_len] = current;
        (*path_len)++;*/
       current->ncnt--;
        int com = cmp(current->attack, current->defense, attack, defense);
        if (com < 0) {
            current = current->left;
        } else if (com > 0) {
            current = current->right;
        } else {
            return current;
        }
    }
    return NULL;
}

node* trade(node* root, int oa, int od, int ra, int rd) {
    if (ra == -1 && rd == -1) {
        printf("1\n");
        return insert(root, oa, od);
    }

    node* path[100]; // Assuming maximum depth of 100 for simplicity
    int path_len = 0;
    node* hell=ispresent(ra,rd,root);
    if(hell==NULL || hell->cnt<=1){
        printf("0\n");
        return root;
    }
    node* temp = find_with_path(ra, rd, root);

    if (temp == NULL || temp->cnt <= 1) {
        printf("0\n");
        return root;
    }

    // Decrement the count and ncnt of the found node and its ancestors
   

    node* another = ispresent(oa, od, root);
    if (another == NULL) {
        printf("1\n");
        root = insert(root, oa, od);
        temp->cnt--;
        temp->ncnt--;
        for (int i = path_len - 2; i >= 0; i--) {
            path[i]->ncnt--;
        }
    } else {
        int com = cmp(oa, od, ra, rd);
        if (com > 0) {
            printf("1\n");
            root = insert(root, oa, od);
            temp->cnt--;
            temp->ncnt--;
            for (int i = path_len - 2; i >= 0; i--) {
                path[i]->ncnt--;
            }
        } else if (com < 0) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }
    return root;
}

node* findlargestinsmallest(node* root, int attack, int defense) {
    node* temp = NULL;
    while (root != NULL) {
        if (cmp(root->attack, root->defense, attack, defense) < 0) {
            temp = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return temp;
}

node* findsmallestinlargest(node* root, int attack, int defense) {
    node* temp = NULL;
    while (root != NULL) {
        if (cmp(root->attack, root->defense, attack, defense) > 0) {
            temp = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return temp;
}

void compare(node* root, int attack, int defense) {
    node* temp = ispresent(attack, defense, root);
    if (temp == NULL) {
        printf("0\n");
    } else {
        printf("%d\n", temp->cnt);
    }

    temp = findlargestinsmallest(root, attack, defense);
    if (temp == NULL) {
        printf("-1\n");
    } else {
        printf("%d %d %d\n", temp->attack, temp->defense, temp->cnt);
    }

    temp = findsmallestinlargest(root, attack, defense);
    if (temp == NULL) {
        printf("-1\n");
    } else {
        printf("%d %d %d\n", temp->attack, temp->defense, temp->cnt);
    }
}

node* kthstrongest(int k, node* root) {
    while (root) {
        int left_count = (root->left ? root->left->ncnt : 0);
        if (left_count >= k) {
            root = root->left;
        } else if (left_count + root->cnt >= k) {
            return root;
        } else {
            k -= (left_count + root->cnt);
            root = root->right;
        }
    }
    return NULL;
}

int sum(node* root) {
    if (root == NULL) return 0;
    return 1 + sum(root->left) + sum(root->right);
}

void print(node* root) {
    if (root == NULL) return;
    print(root->left);
    printf("%d %d %d\n", root->attack, root->defense, root->cnt);
    print(root->right);
}

void shuffle(int arr[][2], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp0 = arr[i][0], temp1 = arr[i][1];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[j][0] = temp0;
        arr[j][1] = temp1;
    }
}

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int arr[n][2];
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    shuffle(arr, n);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i][0], arr[i][1]);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        char op[15];
        scanf("%s", op);
        if (strcmp(op, "TRADE") == 0) {
            int oa, od, ra, rd;
            scanf("%d %d %d %d", &oa, &od, &ra, &rd);
            root = trade(root, oa, od, ra, rd);
        } else if (strcmp(op, "COMPARE") == 0) {
            int attack, defense;
            scanf("%d %d", &attack, &defense);
            compare(root, attack, defense);
        } else if (strcmp(op, "KTH_STRONGEST") == 0) {
            int k;
            scanf("%d", &k);
            node* temp = kthstrongest(k, root);
            if (temp == NULL) {
                printf("-1\n");
            } else {
                printf("%d %d %d\n", temp->attack, temp->defense, temp->cnt);
            }
        }
    }
    printf("%d\n", sum(root));
    print(root);
    return 0;
}