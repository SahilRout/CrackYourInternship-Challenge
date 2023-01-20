//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
       pair<int,int>ans(-1,-1);

      map<int,int>map;

      for(int i=0;i<N;i++){

          if(Edge[i]==-1)continue;

          map[Edge[i]]+=i;

      }

      for(auto it:map){

          if(it.second>=ans.second){ans.second=it.second;ans.first=it.first;}

      }

      return ans.first==-1?0:ans.first;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends