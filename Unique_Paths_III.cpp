class Solution
{
public:
    int ans = 0;
    int empty = 1;
    void solve(vector<vector<int>> &grid, int i, int j, int cur)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
            return;
        if (grid[i][j] == 2)
        {
            if (cur == empty)
                ans++;
            return;
        }
        grid[i][j] = -1;
        solve(grid, i + 1, j, cur + 1);
        solve(grid, i, j + 1, cur + 1);
        solve(grid, i - 1, j, cur + 1);
        solve(grid, i, j - 1, cur + 1);
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int x, y;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
                else if (grid[i][j] == 0)
                    empty++;
            }
        }
        solve(grid, x, y, 0);
        return ans;
    }
};