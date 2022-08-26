class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &mat,int i,int j)
    {
        int n=mat.size();
        int m=mat[0].size();
        if(i==n||j==m)return 1e6;
        if(i==n-1&&j==m-1)
        {
            if(mat[i][j]<=0)return -mat[i][j]+1;
            return 1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=solve(mat,i,j+1);
        int down=solve(mat,i+1,j);
        int minHealth=min(right,down)-mat[i][j];
        return dp[i][j]=(minHealth<=0)?1:minHealth;
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        dp.resize(mat.size()+1,vector<int>(mat[0].size()+1,-1));
        return solve(mat,0,0);
    }
};