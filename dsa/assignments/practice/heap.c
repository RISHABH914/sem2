#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int *a, int *b)
{
    *a = *b + *a - (*b = *a);
}
void heapify(int n, int arr[n], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (arr[index] > arr[parent])
        {
            arr[parent] = arr[index] + arr[parent] - (arr[index] = arr[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}
void siftdown(int n, int arr[n], int index)
{
    while (index < n)
    {
        int child1 = index * 2 + 1;
        int child2 = index * 2 + 2;
        if (child1 < n && child2 < n)
        {
            if (arr[child1] < arr[child2])
            {
                if (arr[child2] > arr[index])
                {
                    swap(&arr[child2], &arr[index]);
                    index = child2;
                }
                else if (arr[child1] > arr[index])
                {
                    swap(&arr[child1], &arr[index]);
                    index = child1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (arr[child1] > arr[index])
                {
                    swap(&arr[child1], &arr[index]);
                    index = child1;
                }
                else if (arr[child2] > arr[index])
                {
                    swap(&arr[child2], &arr[index]);
                    index = child2;
                }
                else
                {
                    break;
                }
            }
        }
        else if (child1 < n)
        {
            if (arr[child1] > arr[index])
            {
                swap(&arr[child1], &arr[index]);
                index = child1;
            }
            else
            {
                break;
            }
        }
        else if (child2 < n)
        {
            if (arr[child2] > arr[index])
            {
                swap(&arr[child2], &arr[index]);
                index = child2;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
void print(int n, int arr[n])
{
    while (n > 0)
    {
        arr[0] = arr[n - 1] + arr[0] - (arr[n - 1] = arr[0]);
        printf("%d ", arr[n - 1]);
        n--;
        siftdown(n, arr, 0);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        heapify(n, arr, i);
    }
    print(n, arr);

    return 0;
}