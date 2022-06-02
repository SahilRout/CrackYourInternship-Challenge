class Solution {
public:
    int uniquePaths(int m, int n,vector<vector<int>>& grid) {
        if(m<1||n<1)return 0;
        if(grid[m-1][n-1]==1)return 0;
        if(m==1&&n==1)return 1;
        return uniquePaths(m,n-1,grid)+uniquePaths(m-1,n,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i<1||j<1)dp[i][j]=0;
                if(i==1&&j==1)dp[i][j]=1;
                if(i>0&&j>0)
                {
                    if(grid[i-1][j-1]==1)dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1&&j==1)continue;
                if(grid[i-1][j-1]==1)continue;
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        
        return dp[m][n];
    }
};