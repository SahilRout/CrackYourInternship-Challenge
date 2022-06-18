// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s1, string s2) {
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

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends