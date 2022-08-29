class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int start=0;
        int end=1;
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            int diff=nums[end]-nums[start];
            while(i+1<nums.size()&&nums[i+1]-nums[i]==diff)
            {
                i++;
                end++;
            }
            int n=(end-start)+1;
            if(n>=3)
            {
                ans+=(n-2)*(n+1-2)/2;
            }
            start=end;
            end++;
        }
        
        return ans;
    }
};