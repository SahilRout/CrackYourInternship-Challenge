class Solution {
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    vector<int> dp;
    int solve(string &s,int i,int j)
    {
        if(i==j)return 0;
        if(isPalindrome(s,i,j))return 0;
        int ans=INT_MAX;
        if(dp[i]!=-1)return dp[i];
        for(int st=i;st<=j;st++)
        {
            if(isPalindrome(s,i,st))
            {
                ans=min(ans,1+solve(s,st+1,j));
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        dp.resize(s.size()+1,-1);
        return solve(s,0,s.size()-1);
    }
};