class Solution {
public:
    int findparent(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return parent[node];
        }
        return parent[node]=findparent(parent[node],parent);
    }
    void Union(int u,int v,vector<int>&parent,vector<int> &rank)
    {
        u=findparent(u,parent);
        v=findparent(v,parent);
        if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[v]>rank[u])
        {
            parent[u]=v;
        }
        else if(rank[v]==rank[u])
        {
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n,0);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        int comp=0;
        for(auto it :connections)
        {
            int x=findparent(it[0],parent);
            int y=findparent(it[1],parent);
            if(x==y)continue;
            else {
                Union(x,y,parent,rank);
                comp++;
            }
        }
        if(connections.size()<n-1)return -1;
        return (n-1)-comp;
    }
};