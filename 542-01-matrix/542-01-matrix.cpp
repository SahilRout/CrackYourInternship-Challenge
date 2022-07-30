class Solution {
public:
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!mat[i][j]){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto it =q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                    int nr=it.first+dirx[i];
                    int nc=it.second+diry[i];
                if(nr>=0&&nc>=0&&nr<m&&nc<n&&!vis[nr][nc])
                {
                    mat[nr][nc]=mat[it.first][it.second]+1;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        return mat;
    }
};