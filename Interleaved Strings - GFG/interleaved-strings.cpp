// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
     int dp[101][101];
    bool solve(int i,int j,int k,string s1,string s2,string s3)
    {
        if(i==0&&j==0){
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>0&&j>0)
        {
            if(s1[i-1]==s3[k-1]&&s2[j-1]==s3[k-1])return dp[i][j]=solve(i-1,j,k-1,s1,s2,s3)||solve(i,j-1,k-1,s1,s2,s3);
        }
        if(i>0)
        {
             if(s1[i-1]==s3[k-1])return dp[i][j]=solve(i-1,j,k-1,s1,s2,s3);
        }
        if(j>0){
            if(s2[j-1]==s3[k-1])return dp[i][j]=solve(i,j-1,k-1,s1,s2,s3);
        }
        return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
            memset(dp,-1,sizeof(dp));
        if(s1.size()+s2.size()!=s3.size())return false;
        int i=s1.size();
        int j=s2.size();
        int k=s3.size();
        return solve(i,j,k,s1,s2,s3);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends