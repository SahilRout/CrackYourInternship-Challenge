class Solution {
public:
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int u=0;
        bool flag=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {q.push({i,j});
                 flag=true;
                }
                if(grid[i][j]==1)u++;
            }
        }
        if(!flag&&!u)return 0;
        int cnt=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int newx=x+dirx[i];
                    int newy=y+diry[i];
                    if(newx>=0&&newy>=0&&newx<m&&newy<n)
                    {
                        if(grid[newx][newy]==1)
                        {
                            grid[newx][newy]=2;
                            q.push({newx,newy});
                            u--;
                        }
                    }
                }
            }
            cnt++;
        }
        if(u!=0)return -1;
        return cnt-1;
    }
};