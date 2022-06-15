class Solution {
public:
    int solve(vector<int>& nums, int target,int n)
    {
        if(n==0&&target==0)return 1;
        if(n==0)return 0;
        return solve(nums,target-nums[n-1],n-1)+solve(nums,target+nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,nums.size());
    }
};