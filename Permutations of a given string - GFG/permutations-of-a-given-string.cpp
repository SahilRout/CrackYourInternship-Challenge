// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	     vector<string> ans;
	    void solve(int i,string s,int n)
	    {
	        if(i==n){
	            ans.push_back(s);
	            return;
	        }
	        set<char> st;
	        for(int j=i;j<n;j++)
	        {
	            if(st.find(s[j])!=st.end())continue;
	            st.insert(s[j]);
	            swap(s[i],s[j]);
	            solve(i+1,s,n);
	            swap(s[i],s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    solve(0,S,S.size());
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends