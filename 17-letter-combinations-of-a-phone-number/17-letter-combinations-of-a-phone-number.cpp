class Solution {
public:
    vector<string> ans;
    void solve(map<char,string> mp,string digits,int i,string temp)
    {
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int x=0;x<mp[digits[i]].size();x++)
        {
            solve(mp,digits,i+1,temp+mp[digits[i]][x]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        solve(mp,digits,0,"");
        
        return ans;
    }
};