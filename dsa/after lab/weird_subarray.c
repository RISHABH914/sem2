#include <stdio.h>

int findMaxK(int arr[], int n, int X) {
    int maxK = -1; // Store the maximum K found
    int left = 0, right = 0, count = 0;

    while (right < n) {
        // Check if the current element meets the threshold condition
        while (right < n && arr[right] > (double)X / (right - left + 1)) {
            right++; // Expand window
            count++; // Track valid subarray length
            if (count > maxK) {
                maxK = count; // Update max K
            }
        }

        // If window breaks condition, shrink it from the left
        while (left <= right && (right < n && arr[right] <= (double)X / (right - left + 1))) {
            left++;
            count--;
        }

        right++; // Move to the next element
    }

    return maxK;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, X;
        scanf("%d %d", &n, &X);
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", findMaxK(arr, n, X));
    }

    return 0;
}
