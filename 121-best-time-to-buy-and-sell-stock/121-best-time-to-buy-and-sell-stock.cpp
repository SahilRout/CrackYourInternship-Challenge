class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++)
        {
            ans=max(prices[i]-min_price,ans);
            min_price=min(min_price,prices[i]);
        }
        return ans;
    }
};