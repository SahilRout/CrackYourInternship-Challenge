class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        int i=0;
        for(auto it : edges)
        {
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;
        }
        priority_queue<pair<double,int>> q;
        q.push({0.0,start});
        vector<double> dist(n,0.0);
        dist[start]=1.0;
        while(!q.empty())
        {
            int node=q.top().second;
            int wt=q.top().first;
            q.pop();
            for(auto it : adj[node])
            {
                if(dist[it.first]<dist[node]*it.second)
                {
                    dist[it.first]=dist[node]*it.second;
                    q.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end];
    }
};