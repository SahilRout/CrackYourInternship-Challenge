// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int dirx[4]={-1,0,1,0};
    int diry[4]={0,1,0,-1};
    bool solve(int i,int j,vector<vector<int>> &grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)return false;
        if(grid[i][j]==2)return true;
        grid[i][j]=0;
        bool ans=false;
        for(int x=0;x<4;x++)
        {
            ans=ans|solve(i+dirx[x],j+diry[x],grid);
        }
        return ans;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return solve(i,j,grid);
                }
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends