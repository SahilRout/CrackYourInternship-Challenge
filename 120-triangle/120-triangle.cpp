class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& triangle)
    {
        if(i==triangle.size()-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(triangle.size(),vector<int>(triangle.size(),-1));
        return solve(0,0,triangle);
    }
};