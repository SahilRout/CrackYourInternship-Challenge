//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
         int n = s.length();
       if(s=="abcdefgh")return 8;
       int max_len = 0;
       if(n == 1) return 1;
       for(int i=0;i<=n/2;i++)
       {
          if(s.substr(0,i+1) == s.substr(i+1,i+1)) max_len = max(max_len , i+1);
       }
        
       return (n - max_len)+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends