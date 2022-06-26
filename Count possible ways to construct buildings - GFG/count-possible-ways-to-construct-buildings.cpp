// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long dp[100001];
	int mod=1e9+7;
	int solve(int n)
	{
	    if(n<=0)return 1;
	    if(dp[n]!=-1)return dp[n];
	    return dp[n]=(solve(n-1)+solve(n-2))%mod;
	}
	int TotalWays(int N)
	{
	    memset(dp,-1,sizeof(dp));
	    long long total=(solve(N))%mod;
	    return (total*total)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends