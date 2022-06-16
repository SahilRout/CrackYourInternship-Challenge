class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans=0;
        for(int g=0;g<n;g++)
        {
            int i=0;
            int j=g;
            while(j<n)
            {
              if(g==0)
              {
                  dp[i][j]=true;
              }
              else if(g==1)
              {
                  dp[i][j]= s[i]==s[j]?true:false;
              }
              else {
                  if(s[i]==s[j] && dp[i+1][j-1]==true)dp[i][j]=true;
              }
                if(dp[i][j])ans++;  
                
                i++;
                j++;
            }
        }
        
        return ans;
        
    }
};