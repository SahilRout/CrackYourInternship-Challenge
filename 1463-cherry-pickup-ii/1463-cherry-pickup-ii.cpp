class Solution {
public:
    int dp[71][71][71];
    int solve(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid)
    {
        if(j1<0||j2<0||j1>=n||j2>=n)return -1e9;
        if(i==m-1)
        {
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=INT_MIN;
        for(int a=-1;a<=1;a++)
        {
            for(int b=-1;b<=1;b++)
            {
                ans=max(ans,solve(i+1,j1+a,j2+b,m,n,grid));
            }
        }
        
        if(j1==j2)return dp[i][j1][j2]=grid[i][j1]+ans;
        return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid[0].size()-1,grid.size(),grid[0].size(),grid);
    }
};