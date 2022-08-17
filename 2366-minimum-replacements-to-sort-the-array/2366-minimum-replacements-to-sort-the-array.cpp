class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int x=nums[i]/prev;
            if(nums[i]%prev!=0)
            {
                x++;
                prev=nums[i]/x;
            }
            ans+=x-1;
        }
        return ans;
    }
};