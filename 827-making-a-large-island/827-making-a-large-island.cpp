class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j,int m,int n,int color)
    {
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1)return 0;
        grid[i][j]=color;
        return 1+helper(grid,i-1,j,m,n,color)+helper(grid,i,j-1,m,n,color)+helper(grid,i+1,j,m,n,color)+helper(grid,i,j+1,m,n,color);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int color=2;
        map<int,int> mp;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    mp[color]=helper(grid,i,j,n,n,color);
                    color++;
                }
            }
        }
        mp[0]=0;
        int ans=mp[2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0){
                    set<int> s;
                  if(i>0)s.insert(grid[i-1][j]);
                   if(j>0) s.insert(grid[i][j-1]);
                   if(i<n-1)s.insert(grid[i+1][j]);
                    if(j<n-1)s.insert(grid[i][j+1]);
                    int tans=1;
                for(auto it : s)
                {
                    tans+=mp[it];
                }
                    ans=max(tans,ans);
              }
            }
        }
        
        return ans;
    }
};