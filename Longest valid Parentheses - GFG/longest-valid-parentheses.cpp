// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        int n=s.size();
        vector<int> dp(n,0);
        int res=0;
        int open=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')open++;
            else if(open>0)
            {
                dp[i]=dp[i-1]+2;
                dp[i]+=(i-dp[i])>=0?dp[i-dp[i]]:0;
                res=max(res,dp[i]);
                open--;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends