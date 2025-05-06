#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
cin.tie(nullptr);
ios_base::sync_with_stdio(false);
    stack<string> sp;
    string input;
    cin>>input;
    string s;
    for(int i=0;i<input.size();i++){
        if(input[i]=='/'){
            if(!s.empty()){
                sp.push(s);
                s.clear();
            }
            while(input[i]=='/'){
                i++;
            }
            i--;
        }else if(input[i]=='.'){
            if(i+1<input.size() && input[i+1]=='.'){
                if(!sp.empty()){
                    sp.pop();
                }
                i++;
            }
        }else{
            s+=input[i];
        }
    }
    if(!s.empty()){
        sp.push(s);
    }
    stack<string> another;
    while(!sp.empty()){
        another.push(sp.top());
        sp.pop();
    }
    if(another.empty()){
        cout<<"/";
    }
    while(!another.empty()){
        cout<<"/";
        cout<<another.top();
        another.pop();
    }
    cout<<endl;

}