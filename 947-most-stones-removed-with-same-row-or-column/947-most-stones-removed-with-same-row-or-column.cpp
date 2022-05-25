class Solution {
public:
    vector<int> parent;
    int findPar(int node)
    {
        if(parent[node]==-1)return node;
        return parent[node]=findPar(parent[node]);
    }
    void Union(int u,int v)
    {
        u=findPar(u);
        v=findPar(v);
        parent[v]=u;
    }
    int removeStones(vector<vector<int>>& stones) {
        parent.resize(20005,-1);
        for(auto it : stones)
        {
            if(findPar(it[0])!=findPar(it[1]+10001))
            {
                Union(it[0],it[1]+10001);
            }
        }
        set<int> s;
        for(auto it : stones )s.insert(findPar(it[0]));
        return stones.size()-s.size();
    }
};