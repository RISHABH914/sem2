#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> qu;
    int n;
    cin>>n;
    int cnt=0;
    long long int sum=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp<0){

            if(sum+temp>=0){
                sum+=temp;
                qu.push(temp);
                cnt++;
            }else{
               if(!qu.empty()){
                int top=qu.top();
                if(top<temp){
                    qu.pop();
                    qu.push(temp);
                    sum-=top;
                    sum+=temp;
                }else{
                    continue;
                }
               }else{
                continue;
               }

            }
        }else{
            sum+=temp;
            cnt++;
        }
    }
    cout<<cnt<<endl;

}