// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int timer=1;
    bool dfs(int node,int parent,vector<int>&vis,vector<int>&tin,vector<int>&low,vector<int> adj[],int c,int d)
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it : adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                if(dfs(it,node,vis,tin,low,adj,c,d))return true;
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    if(it==c&&node==d||node==c&&it==d)
                    {
                        return true;
                    }
                }
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        
        return false;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V,0);
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,vis,tin,low,adj,c,d))return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends