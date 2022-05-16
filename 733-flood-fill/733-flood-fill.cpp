class Solution {
public:
    void solve(int i,int j,int m,int n,vector<vector<int>>& grid, int newColor,int prevColor)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==newColor||grid[i][j]!=prevColor) return;
        grid[i][j]=newColor;
        solve(i+1,j,m,n,grid,newColor,prevColor);
        solve(i,j+1,m,n,grid,newColor,prevColor);
        solve(i-1,j,m,n,grid,newColor,prevColor);
        solve(i,j-1,m,n,grid,newColor,prevColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        solve(sr,sc,grid.size(),grid[0].size(),grid,newColor,grid[sr][sc]);
        return grid;
    }
};