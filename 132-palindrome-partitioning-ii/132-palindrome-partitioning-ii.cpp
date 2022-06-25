class Solution {
public:
    int dp[2001];
    bool isPalindrome(int st,int en,string &s)
    {
        while(st<=en)
        {
            if(s[st]!=s[en])return false;
            st++;
            en--;  
        }
        return true;
    }
    int solve(int i,string &s)
    {
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1e9;
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(i,j,s))
            {
              int cost=1+solve(j+1,s);
                 ans=min(ans,cost);
            }
        }
        
        return dp[i]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s)-1;
    }
};