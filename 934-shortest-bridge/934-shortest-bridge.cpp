class Solution {
public:
    int d1[4]={-1,0,1,0};
    int d2[4]={0,1,0,-1};
    queue<pair<int,int>> q;
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0||vis[i][j]==1)return;
        vis[i][j]=1;
        q.push({i,j});
        dfs(i+1,j,m,n,grid,vis);
        dfs(i,j+1,m,n,grid,vis);
        dfs(i-1,j,m,n,grid,vis);
        dfs(i,j-1,m,n,grid,vis);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            bool flag=true;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid.size(),grid[0].size(),grid,vis);
                    flag=false;
                    break;   
                }
            }
            if(!flag)break;
        }
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int x=i+d1[d],y=j+d2[d];
                if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()){
                if(grid[x][y]==1&&!vis[x][y])return ans;
                if(grid[x][y]==0&&!vis[x][y]){
                    vis[x][y]=1;
                    q.push({x,y});
                }
                }
            }
            }
            ans++;

        }
        return ans;
    }
};