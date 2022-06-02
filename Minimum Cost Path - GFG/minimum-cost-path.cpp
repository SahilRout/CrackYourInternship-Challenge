// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        dis[0][0] = grid[0][0];
        pq.push({dis[0][0],{0, 0}});
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        while(!pq.empty()){
            auto p = pq.top();
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            if(i == n-1 && j == n-1) return p.first;
            for(int k = 0; k < 4; k++)
            {
                  int u = i + x[k];
                  int v = j + y[k];
                  if(u >= 0 && u < n && v >= 0 && v < n && dis[u][v] > dis[i][j]+grid[u][v])
                  {
                      dis[u][v] = dis[i][j] + grid[u][v];
                      pq.push({dis[u][v],{u,v}});
                  }
              }
        }
        return dis[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends