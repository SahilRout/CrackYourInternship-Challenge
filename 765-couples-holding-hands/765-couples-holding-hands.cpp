class Solution {
public:
    vector<int> parent;
    int par(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=par(parent[node]);
    }
    int _union(int u,int v)
    {
        int a=par(u);
        int b=par(v);
        if(a==b)return false;
        parent[b]=a;
        return true;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        parent.resize(n,0);
        for(int i=0;i<n;i+=2)
        {
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            if(_union(i,i+1))ans++;
        }
        return ans;
    }
};