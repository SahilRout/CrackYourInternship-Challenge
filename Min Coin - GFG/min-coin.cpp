// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>coins, int amt)
	{
	     int n=coins.size();
        int dp[n+1][amt+1];
        for(int i=0;i<=amt;i++)dp[0][i]=1e9;
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amt;j++)
            {
                if(j>=coins[i-1])dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][amt]>=1e9?-1:dp[n][amt];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends