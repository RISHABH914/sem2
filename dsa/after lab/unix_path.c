#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
    int front, rear;
    char** arr;
} queue;

void enqueue(queue* q, char* data) {
    q->rear++;
    q->arr[q->rear] = data;
    if (q->front == -1) {
        q->front = 0;
    }
}

void dequeue(queue* q) {
    if (q->front > q->rear) return;
    q->front++;
}

int main() {
    char arr[1000000];
    fgets(arr, sizeof(arr), stdin);

    int n = strlen(arr);
    if (arr[n - 1] == '\n') arr[n - 1] = '\0';
    n = strlen(arr);

    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (char**)malloc(1000000 * sizeof(char*));

    int startIndex = 1;
    for (int i = startIndex; i < n; i++) {
        if (arr[i] == '/') {
            continue;
        } else if (arr[i] == '.' && (i + 1 < n && arr[i + 1] == '.')) {
            dequeue(q);
            i++;
        } else if (arr[i] == '.') {
            continue;
        } else {
            int j = 0;
            char* res = (char*)malloc(256 * sizeof(char));
            while (i < n && arr[i] != '/' && arr[i] != '.') {
                res[j++] = arr[i++];
            }
            res[j] = '\0';
            enqueue(q, res);
            i--;
        }
    }

    printf("/");
    if (q->front <= q->rear) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%s", q->arr[i]);
            if (i < q->rear){ 
                printf("/");
                }
        }
    }
    printf("\n");

    return 0;
}
