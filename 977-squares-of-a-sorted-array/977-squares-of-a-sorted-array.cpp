class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        vector<int> ans(nums.size(),0);
        for(int k=nums.size()-1;k>=0;k--)
        {
            if(abs(nums[r])>abs(nums[l]))
            {
                ans[k]=nums[r]*nums[r];
                r--;
            }
            else {
                ans[k]=nums[l]*nums[l];
                l++;
            }
        }
        return ans;
        
    }
};