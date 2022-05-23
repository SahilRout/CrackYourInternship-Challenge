// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int> st;
	void toposort(int node,vector<int> adj[],vector<int> &vis)
	{
	    vis[node]=1;
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	            toposort(it,adj,vis);
	        }
	    }
	    
	    st.push(node);
	}
	void revDfs(int node,vector<int>&vis,vector<int> adj[])
	{
	    vis[node]=1;
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        revDfs(it,vis,adj);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                toposort(i,adj,vis);
            }
        }
        vector<int> transpose[V];
        for(int i=0;i<V;i++)
        {
          vis[i]=0;
            for(auto it : adj[i])
            {
                transpose[it].push_back(i);
            }
        }
        int ans=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
           // cout<<node<<vis[node]<<endl;
            if(!vis[node])
            {
                revDfs(node,vis,transpose);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends