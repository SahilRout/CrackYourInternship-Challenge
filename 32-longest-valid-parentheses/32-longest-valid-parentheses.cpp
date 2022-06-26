class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        int res=0;
        int open=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')open++;
            else if(open>0)
            {
                dp[i]=dp[i-1]+2;
                dp[i]+=(i-dp[i])>=0?dp[i-dp[i]]:0;
                res=max(res,dp[i]);
                open--;
            }
        }
        
        return res;
    }
};