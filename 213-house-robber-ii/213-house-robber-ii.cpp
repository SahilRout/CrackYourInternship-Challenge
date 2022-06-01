class Solution {
public:
    int solve(vector<int>& nums)
    {
        int dp[nums.size()];
        if(nums.size()==1)return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> t=nums;
        t.pop_back();
        int ans1=solve(t);
        t=nums;
        reverse(t.begin(),t.end());
        t.pop_back();
         reverse(t.begin(),t.end());
        int ans2=solve(t);
        return max(ans1,ans2);
    }
};