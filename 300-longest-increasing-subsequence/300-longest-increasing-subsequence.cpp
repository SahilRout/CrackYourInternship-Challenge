class Solution {
public:
    int dp[2501][2501];
    int solve(vector<int>& nums,int i,int prev)
    {
        if(i==nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1||nums[i]>nums[prev])return dp[i][prev+1]=max(1+solve(nums,i+1,i),solve(nums,i+1,prev));
        return dp[i][prev+1]=solve(nums,i+1,prev);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};