// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>>dp;
    int dfs(int i,int j,vector<vector<int>>& matrix,int m,int n,int prev)
    {
       // cout<<1<<endl;
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(prev>=matrix[i][j])return 0;
       // cout<<2<<endl;
        if(dp[i][j])return dp[i][j];
       // cout<<3<<endl;
       // cout<<4<<endl;
        int ans=1;
        ans=max(ans,1+dfs(i+1,j,matrix,m,n,matrix[i][j]));
        ans=max(ans,1+dfs(i,j+1,matrix,m,n,matrix[i][j]));
        ans=max(ans,1+dfs(i-1,j,matrix,m,n,matrix[i][j]));
        ans=max(ans,1+dfs(i,j-1,matrix,m,n,matrix[i][j]));
       //  cout<<ans<<endl;
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int m, int n) {

           dp=vector<vector<int>>(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res=max(res,dfs(i,j,matrix,m,n,-1));
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends