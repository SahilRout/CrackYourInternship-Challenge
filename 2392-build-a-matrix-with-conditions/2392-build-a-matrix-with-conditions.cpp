class Solution {
public:
    vector<int> topo(vector<int> adj[],int n)
    {
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> adj1[k];
        for(auto it : rowConditions)
        {
            adj1[it[0]-1].push_back(it[1]-1);
        }
        vector<int> adj2[k];
        for(auto it : colConditions)
        {
            adj2[it[0]-1].push_back(it[1]-1);
        }
        vector<int> topo1=topo(adj1,k);
        if(topo1.size()<k)return {};
        vector<int> topo2=topo(adj2,k);
        if(topo2.size()<k)return {};
        
        vector<vector<int>> ans(k,vector<int>(k));
        map<int,int> m;
        for(int i=0;i<k;i++)
        {
            m[topo2[i]]=i;
        }
        for(int i=0;i<k;i++)
        {
            ans[i][m[topo1[i]]]=topo1[i]+1;
        }
        return ans;
    }
};