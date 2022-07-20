class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<int> &vis)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])dfs(adj,it,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
            
        }
        int cnt=0;
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        
        return cnt;
    }
};