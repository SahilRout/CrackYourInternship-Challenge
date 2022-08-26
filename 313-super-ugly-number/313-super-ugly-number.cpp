class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(),primes.end());
        vector<long long> dp(n,INT_MAX);
        dp[0]=1;
        vector<long long> idx(primes.size(),0);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<primes.size();j++)
            {
                //cout<<dp[i]<<endl;
               // cout<<dp[i-1]<<endl;
                dp[i]=min(dp[i],dp[idx[j]]*primes[j]);
            }
              for(int j=0;j<primes.size();j++)
            {
                //cout<<dp[i]<<endl;
               // cout<<dp[i-1]<<endl;
                if(dp[i]==dp[idx[j]]*primes[j])idx[j]++;
            }
        }
        return dp[n-1];
    }
};