class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid)
    {
        if(m<0||n<0)return INT_MAX;
        if(m==0&&n==0)return grid[0][0];
        return grid[m][n]+min(solve(m-1,n,grid),solve(m,n-1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)dp[i][j]=grid[0][0];
                else{
                int up=1e9;
                int down=1e9;
                if(i-1>=0)up=dp[i-1][j];
                if(j-1>=0)down=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,down);
                }
                
            }
        }
        
        return dp[m-1][n-1];
    }
};