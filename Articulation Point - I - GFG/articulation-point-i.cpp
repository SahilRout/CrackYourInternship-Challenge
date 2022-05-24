// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> ans;
    int timer=0;
    void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,vector<int>adj[])
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        int child=0;
        for(auto it : adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&&parent!=-1)
                {
                    ans.push_back(node);
                }
                ++child;
            }
            else if (parent!=it)low[node]=min(low[node],tin[it]);
        }
        if(parent==-1&&child>1)
        {
            ans.push_back(node);
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
         vector<int> vis(V,0);
        vector<int> tin(V,-1);
        vector<int> low(V,-1);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,tin,low,adj);
            }
        }
        sort(ans.begin(),ans.end());
         ans.erase(unique(ans.begin(), ans.end()), ans.end());
        if(ans.empty())return {-1};
        return ans;
    }
};

// { Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends