//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int n,vector<int> a,int q,vector<vector<int>> queries){
      // code here
      vector<long long> pre(n, 0), arr; 
      vector<int> ans;
      
      for(int i = 0; i < n; i++) arr.push_back(a[i]);
      sort(arr.begin(), arr.end());
      
      
      pre[0] = arr[0];
      for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];
      
      for(int i = 0; i < q; i++)
      {
          long long c = queries[i][0], k = queries[i][1], offset = 0, toSub = 0, reach;
          unordered_map<int, int> vis; vector<int> v;
          
          for(int j = 0; j < k; j++) {
              
              int val = a[queries[i][j+2] - 1];
              int indx = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
              
              while(vis[indx]) indx++;
              
              v.push_back(indx);
              vis[indx] = 1;
          }
          sort(v.begin(), v.end());
          
          for(int indx: v) {
              auto it = upper_bound(pre.begin(), pre.end(), c + offset);
              reach = it - pre.begin();
              
              if(reach >= indx) {
                  offset += arr[indx];
                  toSub++;
              }
              else break;
          }
          auto it = upper_bound(pre.begin(), pre.end(), c + offset);
          reach = it - pre.begin();
          
          ans.push_back(reach - toSub); 
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends