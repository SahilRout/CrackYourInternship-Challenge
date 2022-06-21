// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
       int solve(vector<int>& prices,int ind,int n,int buy,vector<vector<vector<int>>> &dp,int cnt)
    {
        if(ind==n)return 0;
        if(cnt==2)return 0;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        if(buy)
        {
            return dp[ind][buy][cnt]=max(solve(prices,ind+1,n,buy,dp,cnt),-prices[ind]+solve(prices,ind+1,n,0,dp,cnt));
        }
        return dp[ind][buy][cnt]=max(solve(prices,ind+1,n,buy,dp,cnt),prices[ind]+solve(prices,ind+1,n,1,dp,cnt+1));
    }
int maxProfit(vector<int>&prices){
     int n=prices.size();
         vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,-1)));
        return solve(prices,0,prices.size(),1,dp,0);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends