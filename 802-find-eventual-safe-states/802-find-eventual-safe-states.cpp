class Solution {
public:
    bool cycleDFS(int node,int parent,vector<int> &vis,vector<vector<int>>& graph)
    {
        vis[node]=1;
        for(auto it : graph[node])
        {
                if(vis[it]==0&&cycleDFS(it,node,vis,graph)||vis[it]==1) return true;
        }
        vis[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
               if(vis[i]==2||!cycleDFS(i,-1,vis,graph))
                   ans.push_back(i);
        }
        return ans;
    }
};