// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,string&s,bool look)
    {
        if(i>j)return 0;
        if(i==j)
        {
            if(look)
            {
                if(s[i]=='T')return 1;
                else return 0;
            }
            else{
                if(s[i]=='F')return 1;
                else return 0;
            }
        }
        if(dp[i][j][look]!=-1)return dp[i][j][look];
        int ans=0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int lt=solve(i,k-1,s,true);
            int lf=solve(i,k-1,s,false);
            int rt=solve(k+1,j,s,true);
            int rf=solve(k+1,j,s,false);
            
            if(s[k]=='&')
            {
                if(look)
                {
                    ans+=(lt*rt);
                }
                else{
                    ans+=(lt*rf)+(lf*rt)+(lf*rf);
                }
            }
            if(s[k]=='|')
            {
                if(look)
                {
                    ans+=(lt*rf)+(lf*rt)+(lt*rt);
                }
                else ans+=(lf*rf);
            }
            if(s[k]=='^')
            {
                if(look)ans+=(lt*rf)+(lf*rt);
                else ans+=(lt*rt)+(lf*rf);
            }
           // dp[i][j][look]=ans%1003;
        }
        return dp[i][j][look]=ans%1003;
    }
    int countWays(int N, string S){
        // code here
        dp.resize(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
        return solve(0,N-1,S,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends