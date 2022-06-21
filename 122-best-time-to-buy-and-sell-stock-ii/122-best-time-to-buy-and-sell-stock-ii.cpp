class Solution {
public:
    int solve(vector<int>& prices,int ind,int n,int buy,vector<vector<int>> &dp)
    {
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
        {
            return dp[ind][buy]=max(solve(prices,ind+1,n,buy,dp),-prices[ind]+solve(prices,ind+1,n,0,dp));
        }
        return dp[ind][buy]=max(solve(prices,ind+1,n,buy,dp),prices[ind]+solve(prices,ind+1,n,1,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,prices.size(),1,dp);
    }
};