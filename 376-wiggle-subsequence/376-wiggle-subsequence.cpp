class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,vector<int> &nums,int last)
    {
        if(i>=nums.size()-1)return 0;
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        if(last==1)
        {
            int take=0;
            if(nums[i+1]-nums[i]>0)
            {
                take= 1+ solve(i+1,nums,-1);
            }
            return dp[i][last+1]=max(take,solve(i+1,nums,last));
            
        }
          if(last==-1)
        {
            int take=0;
            if(nums[i+1]-nums[i]<0)
            {
                take= 1+ solve(i+1,nums,1);
            }
            return dp[i][last+1]=max(take,solve(i+1,nums,last));
        }
        return 0;
    }
    int wiggleMaxLength(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int>(3,-1));
        return 1+max(solve(0,nums,1),solve(0,nums,-1));
    }
};