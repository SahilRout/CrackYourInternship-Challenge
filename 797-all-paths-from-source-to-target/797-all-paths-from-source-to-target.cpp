class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node,vector<vector<int>>&graph,vector<int> ans,vector<int>&vis )
    {
        if(node==graph.size()-1)
        {
            res.push_back(ans);
            return;
        }
        for(auto it : graph[node])
        {
           if(!vis[it])
           {
               vis[it]=1;
                ans.push_back(it);
            dfs(it,graph,ans,vis);
               ans.pop_back();
               vis[it]=0;
           }
            
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vis[0]=1;
        vector<int> ans;
        ans.push_back(0);
        dfs(0,graph,ans,vis);
        return res;
    }
};