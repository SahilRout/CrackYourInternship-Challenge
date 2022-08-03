class Solution {
public:
    void solve(vector<vector<char>> &grid,vector<vector<int>>&vis,int i,int j,int m,int n)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||vis[i][j])return;
        vis[i][j]=1;
        solve(grid,vis,i-1,j,m,n);
        solve(grid,vis,i+1,j,m,n);
        solve(grid,vis,i,j-1,m,n);
        solve(grid,vis,i,j+1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    cnt++;
                    solve(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
        
    }
};