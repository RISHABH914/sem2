#include <stdio.h>
#include <stdlib.h>

typedef struct column {
    int colno;
    struct column* next;
} column;

column* newnode(int colno) {
    column* temp = (column*)malloc(sizeof(column));
    temp->colno = colno;
    temp->next = NULL;
    return temp;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void dfs(column* arr[], int n, int index, int* res, int* cursize, int vis[]) {
    if (index >= n || vis[index]) return;

    vis[index] = 1;
    res[(*cursize)++] = index;

    column* temp = arr[index];
    while (temp != NULL) {
        if (!vis[temp->colno]) {
            dfs(arr, n, temp->colno, res, cursize, vis);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    column* arr[n + 1];  
    for (int i = 0; i <= n; i++) {
        arr[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        column* newA = newnode(b);
        newA->next = arr[a];
        arr[a] = newA;

        column* newB = newnode(a);
        newB->next = arr[b];
        arr[b] = newB;
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int start;
        scanf("%d", &start);

        int res[n + 1], currsize = 0;
        int vis[n + 1];
        for (int i = 0; i <= n; i++) {
            vis[i] = 0;
        }

        dfs(arr, n + 1, start, res, &currsize, vis);
        qsort(res, currsize, sizeof(int), cmp);

        for (int i = 0; i < currsize; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        column* temp = arr[i];
        while (temp) {
            column* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}
