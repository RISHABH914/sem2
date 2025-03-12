/*Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.*/


//so basically the approach is to create two heaps one being max and one being min
//min heap will store minimum of maximum element
//max heap will store maximum of minimum elements
// and therefore by some manipulation we can find the median efficiently based on changing values
#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          // code here
          priority_queue<int,vector<int>> leftheap;   //max heap
          priority_queue<int,vector<int>,greater<int>> rightheap; //min heap
          
          vector<double> res;
          int n=arr.size();
          for(int i=0;i<n;i++){
                  if(leftheap.empty() || arr[i]<=leftheap.top()){
                      leftheap.push(arr[i]);
                  }else{
                      rightheap.push(arr[i]);
                  }
                  
                  if(leftheap.size()>rightheap.size()+1){
                      rightheap.push(leftheap.top());
                      leftheap.pop();
                  }else if(rightheap.size()>leftheap.size()){
                      leftheap.push(rightheap.top());
                      rightheap.pop();
                  }
                  
                  if (leftheap.size() > rightheap.size()) {
                  res.push_back(leftheap.top());
              } else if (leftheap.size() < rightheap.size()) {
                  res.push_back(rightheap.top());
              } else {
                  res.push_back((leftheap.top() + rightheap.top()) / 2.0);
              }
          }
          return res;
      }
  };