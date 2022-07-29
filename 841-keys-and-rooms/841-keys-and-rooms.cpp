class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int node)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it : rooms[i])
            {
                adj[i].push_back(it);
            }
        }
        vector<int> vis(n,0);
        dfs(adj,vis,0);
        for(auto it : vis)
        {
            if(!it)return false;
        }
        return true;
    }
};