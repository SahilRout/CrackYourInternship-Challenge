//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        string ans="";

    for(int i=0;i<s.size();i++){

        if(ans.size()==0 || ans.back()!=s[i]){

            ans+=s[i];

        }

        else ans.pop_back();

    }

    if(ans.size()){

        return ans;

    }

    return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends