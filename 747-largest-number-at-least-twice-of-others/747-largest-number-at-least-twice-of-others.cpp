class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> a=nums;
        sort(nums.begin(),nums.end());
        int x=0;
        int n=nums.size();
        if(nums[n-1]/2>=nums[n-2])x=nums[n-1];
        else return -1;
        for(int i=0;i<a.size();i++)
        {
            if(x==a[i])return i;
        }
        return -1;
    }
};