class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,vector<vector<int>>& matrix)
    {
        
        if(i==matrix.size()-1)
        {
            if(j>=0&&j<matrix[0].size())return matrix[i][j];
        }
        if(j<0||j>=matrix[0].size())return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=matrix[i][j]+min(solve(i+1,j,matrix),min(solve(i+1,j-1,matrix),solve(i+1,j+1,matrix)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix[0].size();i++)
        {
            ans=min(ans,solve(0,i,matrix));
        }
        return ans;
    }
};