class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
     //   cout<<n<<" "<<k<<" ";
    bool dp[n+1][k+1];
    for(int i=1;i<=k;i++)dp[0][i]=false;
    for(int i=0;i<=n;i++)dp[i][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(arr[i-1]>j)dp[i][j]=dp[i-1][j];
            else dp[i][j]=(dp[i-1][j]||dp[i-1][j-arr[i-1]]);
        }
    }
    return dp[n][k];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it : nums)sum+=it;
        if(sum%2!=0)return false;
        sum=sum/2;
        return subsetSumToK(nums.size(),sum,nums);
    }
};