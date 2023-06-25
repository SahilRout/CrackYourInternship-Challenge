class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>> dp;
    int solve(vector<int>&loc,int st,int fin,int fuel)
    {
        if(fuel<0)return 0;
        long long ans=0;
        if(dp[st][fuel]!=-1)return dp[st][fuel];
        for(int i=0;i<loc.size();i++)
        {
            if(i!=st)
            {
                ans=ans%mod+(solve(loc,i,fin,fuel-(abs(loc[st]-loc[i]))))%mod;
           
            }
        }
        if(st==fin)ans++;
        return dp[st][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.resize(locations.size(),vector<long long>(fuel+1,-1));
        return solve(locations,start,finish,fuel);
    }
};