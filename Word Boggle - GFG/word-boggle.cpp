// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    vector<string> ans;
    bool solve(int i,int j,string dict,vector<vector<char> >& board,int idx)
    {
         if(idx==dict.size())
        {
           // cout<<1<<endl;
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]=='1')return false;
        if(board[i][j]!=dict[idx])return false;
        char c=board[i][j];
        board[i][j]='1';
       bool f=solve(i-1,j,dict,board,idx+1);
       f=f|solve(i,j-1,dict,board,idx+1);
       f=f|solve(i+1,j,dict,board,idx+1);
        f=f|solve(i,j+1,dict,board,idx+1);
        f=f|solve(i-1,j-1,dict,board,idx+1);
        f=f|solve(i+1,j-1,dict,board,idx+1);
       f=f| solve(i+1,j+1,dict,board,idx+1);
       f=f| solve(i-1,j+1,dict,board,idx+1);
        board[i][j]=c;
        return f;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dict) {
	    for(auto it : dict)
	    {
	        bool flag=false;
	        for(int i=0;i<board.size();i++)
	        {
	            for(int j=0;j<board[0].size();j++)
	            {
	                if(board[i][j]==it[0])
	                {
	                   flag=solve(i,j,it,board,0);
	                   if(flag)
	                   {
	                       ans.push_back(it);
	                   }
	                }
	                if(flag)break;
	            }
	            if(flag)break;
	        }
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends