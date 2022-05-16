class Solution {
public:
    void solve(vector<vector<char>>& grid,int i,int j,int m,int n)
    {
        if(i>=m||j>=n||i<0||j<0||grid[i][j]=='0')return ;
        grid[i][j]='0';
        solve(grid,i+1,j,m,n);
        solve(grid,i,j+1,m,n);
        solve(grid,i-1,j,m,n);
        solve(grid,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    solve(grid,i,j,grid.size(),grid[0].size());
                }
            }
        }
        
        return ans;
    }
};