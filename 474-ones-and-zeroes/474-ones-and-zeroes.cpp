class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<string>&strs,int m,int n,int index)
    {
        if(index==strs.size())return 0;
        if(dp[index][m][n]!=-1)return dp[index][m][n];
        int countZeros=count(strs[index].begin(),strs[index].end(),'0');
        int countOnes=strs[index].size()-countZeros;
        if(m-countZeros>=0&&n-countOnes>=0)
        return dp[index][m][n]=max(1+solve(strs,m-countZeros,n-countOnes,index+1),solve(strs,m,n,index+1));
        return dp[index][m][n]=solve(strs,m,n,index+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,0);
    }
};