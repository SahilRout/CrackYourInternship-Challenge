class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& triangle)
    {
        if(i==triangle.size()-1)return triangle[i][j];
        if(i>=triangle.size()||j>=triangle[i].size())return 1e6;
        if(dp[i][j]!=-1)return dp[i][j];
        return  dp[i][j]=triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
          dp.resize(m+1,vector<int>(m+1,-1));
        return solve(0,0,triangle);
    }
};