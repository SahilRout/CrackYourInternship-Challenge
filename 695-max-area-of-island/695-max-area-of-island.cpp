class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==2||grid[i][j]==0)return 0;
        grid[i][j]=2;
        return 1+solve(i-1,j,m,n,grid)+solve(i+1,j,m,n,grid)+solve(i,j-1,m,n,grid)+solve(i,j+1,m,n,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,solve(i,j,m,n,grid));
                }
            }
        }
        
        return ans;
    }
};