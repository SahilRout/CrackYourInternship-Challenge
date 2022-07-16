class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> post(n,1);
        vector<int> pre(n,1);
        int x=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=x;
            x=x*nums[i];
        }
        x=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            post[i]=x;
            x=x*nums[i];
            cout<<post[i]<<" ";
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=pre[i]*post[i];
        }
        
        return ans;
    }
};