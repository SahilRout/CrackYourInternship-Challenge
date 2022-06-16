// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
         int n=s.size();
        if(n==1)return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string ans="";
        ans+=s[0];
        for(int g=0;g<n;g++)
        {
            int i=0;
            int j=g;
            int cnt=0;
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
                if(dp[i][j]){
                    if(cnt==0)ans=s.substr(i,g+1);
                    cnt++;
                };  
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends