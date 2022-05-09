class Solution {
public:
     vector<vector<string>> ans;
    bool isPalindrome(string s,int st,int en)
    {
        while(st<=en)
        {
            if(s[st++]!=s[en--])return false;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> temp)
    {
        if(idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> t;
        solve(0,s,t);
        return ans;
    }
};