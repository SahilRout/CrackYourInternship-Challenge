class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n=graph.size();
        vector<int> vis(n,2);
        for(int i=0;i<n;i++)
        {
           if(vis[i]==2)
           {
                 q.push(i);
        vis[i]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it : graph[node])
            {
                if(vis[it]==2)
                {
                    vis[it]=1-vis[node];
                    q.push(it);
                }
                else {
                    if(vis[it]==vis[node])return false;
                }
            }
        }
           }
        }
        for(auto it : vis)cout<<it<<" ";
        return true;
    }
};