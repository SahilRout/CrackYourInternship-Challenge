// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int dp[501][501];
    int solve(int i,int j,vector<vector<int>>& matrix)
    {
        
        if(i==matrix.size()-1)
        {
            if(j>=0&&j<matrix[0].size())return matrix[i][j];
        }
        if(j<0||j>=matrix[0].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=matrix[i][j]+max(solve(i+1,j,matrix),max(solve(i+1,j-1,matrix),solve(i+1,j+1,matrix)));
    }
    int maximumPath(int N, vector<vector<int>> matrix)
    {
          int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix[0].size();i++)
        {
            int x=solve(0,i,matrix);
           // cout<<x<<endl;
            ans=max(ans,x);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends