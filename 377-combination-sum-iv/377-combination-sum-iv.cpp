class Solution {
public:
    int dp[1001];
    int solve(int tar,vector<int>& nums)
    {
        int n=nums.size();
        if(tar==0)return 1;
        int ans=0;
        if(dp[tar]!=-1)return dp[tar];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=tar)
                ans+=solve(tar-nums[i],nums);
        }
        return dp[tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(target,nums);
    }
};