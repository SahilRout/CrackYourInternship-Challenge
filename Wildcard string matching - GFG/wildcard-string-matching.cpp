// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string p, string s)
    {
         int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++)dp[i][0]=false;
        for(int i=1;i<=n;i++)
        {
            bool flag=true;
            for(int j=1;j<=i;j++){
                if(p[j-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][i]=flag;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        
        return dp[m][n];
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends