class Solution {
public:
    int dp[501];
    int solve(int i,int k,vector<int> &arr)
    {
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int len=0;
        int maxNo=INT_MIN;
        int ans=INT_MIN;
        int n=arr.size();
        for(int j=i;j<min(n,i+k);j++)
        {
            maxNo=max(maxNo,arr[j]);
            len++;
            int sum=len*maxNo+solve(j+1,k,arr);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,arr);
    }
};