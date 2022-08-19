class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int end,int n,vector<int>& slices)
    {
        if(n==0){
            return 0;
        }
        if(i>end)return  0;
        if(dp[i][n]!=-1)return dp[i][n];
        return dp[i][n]=max(slices[i]+solve(i+2,end,n-1,slices),solve(i+1,end,n,slices));
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int case1=solve(0,n-2,n/3,slices);
        dp.clear();
        dp.resize(n+1,vector<int>(n+1,-1));
        int case2=solve(1,n-1,n/3,slices);
        return max(case1,case2);
        
    }
};