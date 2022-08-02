class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&matrix,int i,int j,int m,int n,vector<vector<int>>&vis,int prev)
    {
        if(i<0||j<0||i>=m||j>=n||vis[i][j]||matrix[i][j]<=prev)return 0;
       // vis[i][j]=1;
        if(dp[i][j]!=0)return dp[i][j];
        int a=solve(matrix,i-1,j,m,n,vis,matrix[i][j]);
        int b=solve(matrix,i,j-1,m,n,vis,matrix[i][j]);
        int c=solve(matrix,i+1,j,m,n,vis,matrix[i][j]);
        int d=solve(matrix,i,j+1,m,n,vis,matrix[i][j]);
       // vis[i][j]=0;
        int x=max({a,b,c,d});
        dp[i][j]=1+x;
        return 1+x;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        memset(dp,0,sizeof(dp));
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,solve(matrix,i,j,m,n,vis,-1));
            }
        }
        
        return ans;
    }
};