class Solution {
public:
    vector<vector<int>> dp;
    int solve(int m,int n,vector<vector<int>>& obstacleGrid)
    {
        if(m==1&&n==1&&obstacleGrid[m-1][n-1]!=1)return 1;
        if(m<1||n<1)return 0;
        if(obstacleGrid[m-1][n-1]==1)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=solve(m-1,n,obstacleGrid)+solve(m,n-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(m,n,obstacleGrid);
    }
};