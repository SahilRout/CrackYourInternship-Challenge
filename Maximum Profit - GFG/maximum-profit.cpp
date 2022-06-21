// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
             int solve(int prices[],int ind,int n,int buy,vector<vector<vector<int>>> &dp,int cnt)
    {
        if(ind==n)return 0;
        if(cnt==0)return 0;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        if(buy)
        {
            return dp[ind][buy][cnt]=max(solve(prices,ind+1,n,buy,dp,cnt),-prices[ind]+solve(prices,ind+1,n,0,dp,cnt));
        }
        return dp[ind][buy][cnt]=max(solve(prices,ind+1,n,buy,dp,cnt),prices[ind]+solve(prices,ind+1,n,1,dp,cnt-1));
    }
    int maxProfit(int k, int n, int prices[]) {
         vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(k+1,-1)));
        return solve(prices,0,n,1,dp,k);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends