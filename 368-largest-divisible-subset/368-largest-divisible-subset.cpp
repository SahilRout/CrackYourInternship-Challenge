class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++)hash[i]=i;
        int len=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0||nums[j]%nums[i]==0)&&dp[i]<=dp[j])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                    len=max(len,dp[i]);
                }
            }
        }
        int i=0;
        for(i=0;i<n;i++)
        {
            if(dp[i]==len)break;
        }
        vector<int> ans;
        ans.push_back(nums[i]);
        while(hash[i]!=i)
        {
            ans.push_back(nums[hash[i]]);
            i=hash[i];
        }
        return ans;
        
    }
};