class Solution {
public:
    vector<int> dp;
    int solve(int n)
    {
        if(n==0)return 1;
        int ans=1;
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,i*solve(n-i));
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        int ans=1;
        dp.resize(n+1,-1);
        for(int i=1;i<n;i++)
        {
            ans=max(ans,i*solve(n-i));
        }
        
        return ans;
    }
};