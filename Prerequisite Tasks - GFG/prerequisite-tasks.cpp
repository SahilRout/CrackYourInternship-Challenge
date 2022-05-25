// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &dfsVis,vector<int> adj[])
    {
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsVis,adj))return true;
            }
            else if(dfsVis[it]==1)return true;
        }
        dfsVis[node]=0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto it : prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    vector<int> vis(N,0);
	    vector<int> dfsVis(N,0);
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i,vis,dfsVis,adj)){
	           // cout<<i<<endl;
	            return false;
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
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends