class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &v,int i,int j)
    {
        if(i+1==j)return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i+1;k<=j-1;k++)
        {
            ans=min(ans,v[i]*v[j]*v[k]+solve(v,i,k)+solve(v,k,j));
        }
        return  dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        dp.resize(values.size(),vector<int>(values.size(),-1));
        int n=values.size();
        return solve(values,0,n-1);
    }
};