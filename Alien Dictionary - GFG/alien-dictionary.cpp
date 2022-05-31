// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    stack<char> st;
    void dfs(int node,map<int,vector<int>> mp,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it : mp[node])
        {
            if(!vis[it])
            {
                dfs(it,mp,vis);
            }
        }
        st.push(node+'a');
    }
    string findOrder(string dict[], int N, int K) {
        map<int,vector<int>> mp;
        for(int i=0;i<N-1;i++)
        {
            string x=dict[i];
            string y=dict[i+1];
            for(int j=0;j<min(x.size(),y.size());j++)
            {
                if(x[j]!=y[j])
                {
                    mp[x[j]-'a'].push_back(y[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> vis(K,0);
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
            {
                dfs(i,mp,vis);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends