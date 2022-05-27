class Solution {
public:
    void dfs(string x,string y,set<string> vis,double &ans,double temp,map<string,vector<pair<string,double>>> adj)
    {
        if(x==y){
            ans=temp;
            return;
        }
        vis.insert(x);
        for(auto it : adj[x])
        {
            if(vis.find(it.first)!=vis.end())
            {
                continue;
            }
            else{
                dfs(it.first,y,vis,ans,temp*it.second,adj);
            }
        }
    }
        
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++)
        {
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++)
        {
            string x=queries[i][0];
            string y=queries[i][1];
            double ans=-1.0;
            set<string> vis;
            if(adj.find(x)!=adj.end()&&adj.find(y)!=adj.end())
            {
                dfs(x,y,vis,ans,1.0,adj);
            }
            res.push_back(ans);
        }
        
        return res;
        
    }
};