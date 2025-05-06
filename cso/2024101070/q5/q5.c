#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int16_t solve(int16_t arr[],int16_t n);
// {
//     long long int left=0;
//     long long int right =n-1;
//     while (left < right) {
//         int mid = left + (right - left) / 2;
            // if(mid>0 && mid<n-1){
//         if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
//             return arr[mid];  // Found peak
//         } 
//         else if (arr[mid] < arr[mid + 1]) {
//             left = mid + 1;  // Peak is on the right
//         } 
//         else {
// //             right = mid;  // Peak is on the left
// //         }
//             }else if(mid==0){
//                 if(arr[mid+1]<arr[mid]){
//                     return arr[mid];
//                 }
//             }else{
//                 if(arr[mid-1]<arr[mid]){
//                     return arr[mid];
//                 }
//             }
//     }
//     return arr[left];  // Returning the peak element
// }
int main(){
    int16_t n;
    scanf("%hd",&n);
   int16_t arr[n];
    for(int i=0;i<n;i++){
        scanf("%hd",&arr[i]);
    }
    printf("%hd\n",solve(arr,n));

}