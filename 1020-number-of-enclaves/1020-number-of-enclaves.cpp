class Solution {
public:
    vector<vector<int>> vis;
    int solve(vector<vector<int>>&grid,int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0||vis[i][j]==1)return 0;
        vis[i][j]=1;
        return 1+solve(grid,i-1,j,m,n)+solve(grid,i,j-1,m,n)+solve(grid,i+1,j,m,n)+solve(grid,i,j+1,m,n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)cnt++;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)cnt-=solve(grid,i,0,m,n);
            if(grid[i][n-1]==1)cnt-=solve(grid,i,n-1,m,n);
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)cnt-=solve(grid,0,i,m,n);
            if(grid[m-1][i]==1)cnt-=solve(grid,m-1,i,m,n);
        }
        return cnt;
    }
    
};