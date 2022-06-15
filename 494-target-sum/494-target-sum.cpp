class Solution {
public:
    int dp[21][10001+1];
    int solve(vector<int>& nums, int sum,int n)
    {
        if(n==0&&sum==0)return 1;
        if(n==0)return 0;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(nums[n-1]>sum)return dp[n][sum] =solve(nums,sum,n-1);
        return dp[n][sum]=solve(nums,sum-nums[n-1],n-1)+solve(nums,sum,n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum-target<0||(sum-target)%2!=0)return 0;
        sum=(sum-target)/2;
        return solve(nums,sum,nums.size());
    }
};