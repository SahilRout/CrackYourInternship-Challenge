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
        int dp[m+1][n+1];
        for(int i=0;i<=n;i++)dp[0][i]=i;
        for(int j=0;j<=m;j++)dp[j][0]=j;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        
        return dp[m][n];
    }
};