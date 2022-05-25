class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)q.push({i,j});
                else if(grid[i][j]==0)flag=true;
            }
        }
        if(!flag)return -1;
        int dist=0;
        
        while(!q.empty())
        {
            int s=q.size();
            dist++;
            while(s--)
            {
                   int x=q.front().first;
            int y=q.front().second;
                q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==0)
                {
                    q.push({nx,ny});
                    grid[nx][ny]=1;
                }
            }
            }
        }
        
        return dist-1;
    }
};