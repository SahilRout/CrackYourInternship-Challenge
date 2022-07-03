class Solution {
public:
    int dp[10001];
    int solve(int n,int m)
    {
      //cout<<n<<" "<<m<<endl;
        if(n==0)return 0;
         if(n<m*m)return 1e9;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=min(1+solve(n-(m*m),m),solve(n,m+1));
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,1);
    }
};