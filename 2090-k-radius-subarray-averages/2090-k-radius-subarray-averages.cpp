class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)prefix[i]=prefix[i-1]+nums[i];
        vector<int>ans(n,-1);
        int x=(2*k)+1;
        for(int i=0;i<n;i++)
        {
            
            if(i-k<0||i+k>=n)continue;
            if(i-k==0)
            {
                ans[i]=prefix[i+k]/x;
            }
            else ans[i]=(prefix[i+k]-prefix[i-k-1])/x;
        }
        return ans;
        
    }
};