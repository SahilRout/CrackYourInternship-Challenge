//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
          vector<int>d(32,0),x(32,0),c(32,1);

        int k=0,i=0;

        while(b!=0){

            if(b%2==1) k++;

            b/=2;

        }

        while(a!=0){

            d[i]=a%2;

            a/=2;

            i++;

        }

        i=31;

        while(i>=0&&k>0){

            if(d[i]==1){

                x[i]=1;

                k--;

            }

            i--;

        }

        if(k>0){

            i=0;

            while(i<32&&k>0){

                if(x[i]!=1){

                    x[i]=1;

                    k--;

                }

                i++;

            }

        }

        int ans=x[0];

        for(i=1;i<32;i++){

            c[i]=2*c[i-1];

            ans+=x[i]*c[i];

        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends