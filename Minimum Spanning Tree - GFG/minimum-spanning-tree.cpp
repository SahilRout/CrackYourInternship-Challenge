// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findpar(int node,vector<int>&par)
	{
	    if(node==par[node])
	    {
	        return node;
	    }
	    return par[node]=findpar(par[node],par);
	}
	void Union(int u,int v,vector<int> &par,vector<int> &rank)
	{
	    u=findpar(u,par);
	    v=findpar(v,par);
	    if(rank[u]<rank[v])
	    {
	        par[u]=v;
	    }
	    else if(rank[u]>rank[v])
	    {
	        par[v]=u;
	    }
	    else{
	        par[v]=u;
	        rank[u]++;
	    }
	}
	struct node{
	    int u,v,wt;
	    node(int a,int b,int c)
	    {
	        u=a;
	        v=b;
	        wt=c;
	    }
	};
	static bool comp(node a,node b)
	{
	    return a.wt<b.wt;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<node> edges;
        vector<int> par(V);
        vector<int> rank(V);
        for(int i=0;i<V;i++)
        {
            for(auto it :adj[i])
            {
                edges.push_back(node(i,it[0],it[1]));
            }
            par[i]=i;
            rank[i]=0;
        }
        sort(edges.begin(),edges.end(),comp);
        vector<pair<int,int>> mst;
        int ans=0;
        for(auto it : edges)
        {
            if(findpar(it.u,par)!=findpar(it.v,par))
            {
                ans+=it.wt;
                mst.push_back({it.u,it.v});
                Union(it.u,it.v,par,rank);
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends