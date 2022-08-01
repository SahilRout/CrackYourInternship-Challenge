class Solution {
public:
    vector<int> vis,tin,low;
    vector<vector<int>>ans;
    int timer=0;
    void solve(int node,int parent,vector<int> adj[])
    {
        vis[node]=1;
        low[node]=tin[node]=timer++;
        for(auto it :adj[node])
        {
            if(it==parent)continue;
            if(!vis[it])
            {
                solve(it,node,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    ans.push_back({it,node});
                }
            }
            else low[node]=min(low[node],tin[it]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections )
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vis.resize(n,0);
        tin.resize(n,0);
        low.resize(n,0);
        solve(0,-1,adj);
        return ans;
    }
};