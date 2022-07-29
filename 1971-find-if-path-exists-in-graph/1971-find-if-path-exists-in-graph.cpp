class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        queue<int> q;
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vis[source]=0;
        q.push(source);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it : adj[x])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                    if(it==destination)return true;
                }
            }
            
        }
        
        return false;
    }
};