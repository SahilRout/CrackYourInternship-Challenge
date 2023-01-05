//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
       sort(words.begin(),words.end());
        map<string,int> mp;
        for(auto it:words)
            mp[it]=1;
            
        string s="";
        for(int i=words.size()-1;i>=0;i--)
        {
            string w=words[i];
            bool f=true;
            for(int j=0;j<w.length();j++)
            {
                string k=w.substr(0,j+1);
                if(mp.find(k)==mp.end()){
                    f=false;
                    break;
                }
            }
            if(f==true && s.length()<=w.length())
                s=w;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends