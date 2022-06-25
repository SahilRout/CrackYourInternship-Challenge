// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long Total=1e18;
    bool flag=false;
    long long solve(vector<int> adj[],int *cap,vector<int> &vis,int src)
    {
        vis[src]=1;
        long long ans=0;
        int count=0;
        for(auto it : adj[src])
        {
            if(!vis[it])
            {
                count++;
                long long temp=solve(adj,cap,vis,it);
                ans=max(temp,ans);
            }
        }
        long long waterReq=count*ans+cap[src-1];
        if(waterReq>Total)
        {
            flag=true;
        }
        return waterReq;
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       vector<int> vis(N+1,0);
       vector<int> adj[N+1];
       for(auto it : Edges)
       {
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       long long ans=solve(adj,Cap,vis,S);
       return flag==true?-1:ans;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends