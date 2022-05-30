class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j,int gridId)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid.size()||grid[i][j]!=1)return 0;
        grid[i][j]=gridId;
        return 1+helper(grid,i-1,j,gridId)+helper(grid,i,j-1,gridId)+helper(grid,i+1,j,gridId)+helper(grid,i,j+1,gridId);
    }
    int largestIsland(vector<vector<int>>& grid) {
        map<int,int> mp;
        mp[0]=0;
        int n=grid.size();
        int gridId=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int size=helper(grid,i,j,gridId);
                    mp[gridId]=size;
                    gridId++;
                }
            }
        } 
        int res=mp[2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> v;
                    if(i>0)v.insert(grid[i-1][j]);
                    if(j>0)v.insert(grid[i][j-1]);
                    if(i<n-1)v.insert(grid[i+1][j]);
                    if(j<n-1)v.insert(grid[i][j+1]);
                    int sum=1;
                    for(int it : v)sum+=mp[it];
                    res=max(res,sum);
                }
            }
        }
        
        return res;
    }
};