#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct data {
    int start;
    int end;
} data;

int cmp(data a1, data b1) {
    int len1 = a1.end - a1.start;
    int len2 = b1.end - b1.start;
    if (len1 == len2) {
        return a1.start - b1.start;
    }
    return len1 - len2;
}

void merge(data arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    data leftarray[n1], rightarray[n2];

    for (int i = 0; i < n1; i++)
        leftarray[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightarray[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (cmp(leftarray[i], rightarray[j]) <= 0) {
            arr[k] = leftarray[i];
            i++;
        } else {
            arr[k] = rightarray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftarray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightarray[j];
        j++;
        k++;
    }
}


void mergeSort(data arr[], int left, int right) {
    if (left < right) {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    data arr[n];

    for (int i = 0; i < n; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        arr[i].start = start;
        arr[i].end = end;
    }

    // Sort using Merge Sort
    mergeSort(arr, 0, n - 1);

    int k;
    scanf("%d", &k);
    while (k--) {
        int index;
        scanf("%d", &index);
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].end >= index && arr[i].start <= index) {
                printf("%d\n", arr[i].end - arr[i].start + 1);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("-1\n");
        }
    }

}
