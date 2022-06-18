class Solution {
public:
    int dp[501][501];
    int solve(string s1,string s2,int i,int j)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
        {
            return dp[i][j]=solve(s1,s2,i-1,j-1);
        }
        return dp[i][j]=1+min(solve(s1,s2,i,j-1),min(solve(s1,s2,i-1,j),solve(s1,s2,i-1,j-1)));
    }
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,m-1,n-1);
    }
};