#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Queue
{
    int front, rear, size;
    int capacity;
    struct Node **array;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (struct Node **)malloc(queue->capacity * sizeof(struct Node *));
    return queue;
}

void enqueue(struct Queue *queue, struct Node *item)
{
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

struct Node *dequeue(struct Queue *queue)
{
    struct Node *item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

struct Node *front(struct Queue *queue)
{
    return queue->array[queue->front];
}

struct Node *createTree(int arr[], int n)
{
    struct Queue *q = createQueue(10001);

    struct Node *root = newNode(arr[0]);
    enqueue(q, root);
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] == -1)
            front(q)->left = NULL;
        else
        {
            struct Node *node = newNode(arr[i]);
            front(q)->left = node;
            enqueue(q, node);
        }
        if (i + 1 == n)
            break;
        if (arr[i + 1] == -1)
            front(q)->right = NULL;
        else
        {
            struct Node *node = newNode(arr[i + 1]);
            front(q)->right = node;
            enqueue(q, node);
        }
        dequeue(q);
    }
    return root;
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
void getmaxheight(struct Node* root,int* maxheight,int curheight){
    if(root==NULL){
        return;
    }
    (*maxheight)=max(*maxheight,curheight);
    getmaxheight(root->left,maxheight,curheight+1);
    getmaxheight(root->right,maxheight,curheight+1);

}
void print(struct Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
void sumup(struct Node* root,int* sum,int maxheight,int curr){
    if(root==NULL){
        return;
    }

    if(curr==maxheight){
        (*sum)+=root->data;
        return;
    }
    sumup(root->left,sum,maxheight,curr+1);
    sumup(root->right,sum,maxheight,curr+1);
    
}
int deepestLeavesSum(struct Node *root)
{
    // your code here
    int maxheight=0;
    getmaxheight(root,&maxheight,0);
   // print(root);
    //printf("\n\n\n");
int sum=0;
    sumup(root,&sum,maxheight,0);
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = createTree(arr, n);
    printf("%d\n", deepestLeavesSum(root));
    return 0;
}