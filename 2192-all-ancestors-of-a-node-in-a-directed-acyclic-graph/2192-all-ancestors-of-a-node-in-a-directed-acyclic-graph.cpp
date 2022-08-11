class Solution {
public:
    void dfs(int node,int parent,vector<int> adj[],vector<vector<int>> &ans,vector<int> &vis)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
            ans[it].push_back(parent);
            dfs(it,parent,adj,ans,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++)
        {
                 vector<int> vis(n,0);
            dfs(i,i,adj,ans,vis);
        }
        return ans;
    }
};