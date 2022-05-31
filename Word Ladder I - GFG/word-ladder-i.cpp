// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> dict;
        bool flag=0;
        if(startWord==targetWord)return 0;
        for(auto it : wordList)
        {
            if(it==targetWord)flag=1;
            dict.insert(it);
        }
        if(!flag)return 0;
      int  dist=0;
        queue<string> q;
        q.push(startWord);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                string curr=q.front();
                q.pop();
                string temp=curr;
                if(curr==targetWord)return dist+1;
                for(int i=0;i<temp.size();i++)
                {
                    temp=curr;
                    for(char k='a';k<='z';k++)
                    {
                        temp[i]=k;
                        if(temp==curr)continue;
                        if(dict.find(temp)!=dict.end())
                        {
                            q.push({temp});
                            dict.erase(temp);
                        }
                    }
                }
            }
            dist++;
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends