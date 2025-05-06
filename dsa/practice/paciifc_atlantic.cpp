//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
  void pacific(vector<vector<int>>& mat,vector<vector<int>>& res,int x,int y,int n,int m,vector<vector<int>>& vis){
     if(vis[x][y]){
         return;
     }
      int tempx[]={0,0,1,-1};
      int tempy[]={1,-1,0,0};
      res[x][y]=1;
      vis[x][y]=1;
      for(int i=0;i<4;i++){
          int newx=x+tempx[i];
          int newy=y+tempy[i];
          if(newx>=0 && newx<n && newy>=0 && newy<m){
              if(mat[newx][newy]>=mat[x][y]){
                  pacific(mat,res,newx,newy,n,m,vis);
              }
          }
      }
  }
  
  void atlantic(vector<vector<int>>& mat,vector<vector<int>>& res,int x,int y,int n,int m,vector<vector<int>>& vis){
       if(vis[x][y]){
         return;
     }
      int tempx[]={0,0,1,-1};
      int tempy[]={1,-1,0,0};
      res[x][y]=1;
      for(int i=0;i<4;i++){
          int newx=x+tempx[i];
          int newy=y+tempy[i];
          if(newx>=0 && newx<n && newy>=0 && newy<m){
              if(mat[newx][newy]>=mat[x][y]){
                  atlantic(mat,res,newx,newy,n,m,vis);
              }
          }
      }
  }
    int countCoordinates(vector<vector<int> > &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> res1(n, vector<int>(m, 0));  // n x m matrix filled with 0s
vector<vector<int>> res2(n, vector<int>(m, 0));  // Another n x m matrix filled with 0s
vector<vector<int>> vis(n,vector<int>(m,0));
vector<vector<int>> vis2(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            pacific(mat,res1,0,i,n,m,vis);
            atlantic(mat,res2,n-1,i,n,m,vis2);
        }
        
        for(int i=0;i<n;i++){
             pacific(mat,res1,i,0,n,m,vis);
            atlantic(mat,res2,i,m-1,n,m,vis2);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(res1[i][j]==1 && res2[i][j]==1){
                        cnt++;
                    }
            }
        }
        
        return cnt;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.countCoordinates(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends