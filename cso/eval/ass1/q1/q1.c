#include <stdio.h>

long long int find_lonely_number(long long int *arr, long long int *freq,long long int size);
//assuming that initialising frequency array in c is allowed
int main() {
    long long int n;
    scanf("%lld", &n);
    long long int arr[3 * n + 1];
    long long int freq[10000] = {0};  // Initialize frequency array to 0

    for (int i = 0; i < 3 * n + 1; i++) {
        scanf("%lld", &arr[i]);
    }

    printf("%lld\n",find_lonely_number(arr, freq, 3 * n + 1));

    return 0;
}