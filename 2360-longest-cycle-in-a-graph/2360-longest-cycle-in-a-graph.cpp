class Solution {
public:
    int hasCycle(int sv,vector<int> &edges,vector<bool> &vis,set<int>&s)
    {
        vis[sv]=true;
        s.insert(sv);
        if(s.find(edges[sv])!=s.end())return sv;
        if(edges[sv]!=-1&&!vis[edges[sv]])
        {
            int x=hasCycle(edges[sv],edges,vis,s);
            if(x!=-1)return x;
        }
        s.erase(sv);
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(edges.size(),false);
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            set<int> S;
            int getAns=hasCycle(i,edges,vis,S);
            if(getAns>-1)
            {
                int c=1;
                int sv=getAns;
                while(edges[sv]!=getAns)
                {
                    sv=edges[sv];
                    c++;
                }
                ans=max(ans,c);
            }
        }
        
        return ans;
    }
};