class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0]=1;
        int t3=0;
        int t2=0;
        int t5=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=min({2*dp[t2],3*dp[t3],5*dp[t5]});
            if(dp[i]==2*dp[t2])t2++;
            if(dp[i]==3*dp[t3])t3++;
            if(dp[i]==5*dp[t5])t5++;
            cout<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};