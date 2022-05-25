class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e4+1));
        for(int i=0;i<n;i++)
        {
            dist[i][i]=0;
        }
        for(auto it: edges)
        {
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==1e4+1||dist[k][j]==1e4+1)continue;
                    else if(dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        vector<int> ans(n,0);
        int mini=INT_MAX;
        int res=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)ans[i]++;
            }
            //cout<<i<<" "<<ans[i]<<endl;
            if(mini>=ans[i])
            {
                res=i;
                mini=ans[i];
            }
        }
        return res;
        
    }
};