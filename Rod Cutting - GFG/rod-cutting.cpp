// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[],int n,int N)
  {
      if(n==0||N==0)
      {
          return 0;
      }
      if(N>=n)
      {
          return max(price[n-1]+solve(price,n,N-n),solve(price,n-1,N));
      }
      return solve(price,n-1,N);
  }
    int cutRod(int price[], int n) {
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j>=i)
                {
                    dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends