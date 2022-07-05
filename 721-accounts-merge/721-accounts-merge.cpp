class Solution {
public:
    set<string> s;
    void solve(vector<string>&a,vector<int>adj[],int node,vector<vector<string>>& accounts,vector<int> &vis)
    {
        vis[node]=1;
        for(int i=1;i<accounts[node].size();i++)
        {
            if(s.find(accounts[node][i])==s.end()){
            a.push_back(accounts[node][i]);
            s.insert(accounts[node][i]);
            }
        }
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                solve(a,adj,it,accounts,vis);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>adj[n];
        map<string,int> mp;
        int x=0;
        for(auto it : accounts)
        {
            for(int i=1;i<it.size();i++)
            {
                if(mp.find(it[i])!=mp.end())
                {
                    adj[mp[it[i]]].push_back(x);
                    adj[x].push_back(mp[it[i]]);
                   // accounts[x].erase(accounts[x].begin()+);
                }
                else mp[it[i]]=x;
            }
            x++;
        }
        vector<vector<string>> ans;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                //cout<<i<<endl;
                vector<string> a;
                 a.push_back(accounts[i][0]);
                solve(a,adj,i,accounts,vis);
                sort(a.begin()+1,a.end());
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};