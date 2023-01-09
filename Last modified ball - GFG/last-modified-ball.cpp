//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n, vector<int> a) {
        // code here
        int pos=0;
      int carry=1;
      for(int i=n-1;i>=0;i--){
          if((a[i]+carry)<=9){
              pos=i;
              break;
          }
          else carry=(a[i]+carry)/10;
          
      }
      return pos+1;

    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends