class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void dfs(vector<int> adj[], vector<int> &vis, int node)
    {
        ans.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(adj, vis, it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        dfs(adj, vis, 0);
        return ans;
    }
};