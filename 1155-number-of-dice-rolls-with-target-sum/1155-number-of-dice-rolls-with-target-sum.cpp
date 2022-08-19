class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int solve(int target,int n,int k)
    {
        if(target==0&&n==0){
           // cout<<1<<endl;
            return 1;
        }
        if(n<=0||target<=0)return  0;
        if(dp[target][n]!=-1)return dp[target][n];
        int ans=0;
        for(int i=1;i<=k;i++)
        {
          ans=((ans%mod)+solve(target-i,n-1,k)%mod)%mod;
         //ans=ans%mod;
        }
        return dp[target][n]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(target+2,vector<int>(n+1,-1));
        return solve(target,n,k);
    }
};