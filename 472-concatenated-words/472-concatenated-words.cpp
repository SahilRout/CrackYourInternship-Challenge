class Solution {
public:
    bool isConcat(string &s,set<string> &st)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string suffix=s.substr(i);
            if(st.find(s.substr(0,i))!=st.end()&&(st.find(suffix)!=st.end()||isConcat(suffix,st)))return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> s;
        for(auto it : words)
        {
            s.insert(it);
        }
        vector<string> ans;
        for(auto it : words)
        {
            if(isConcat(it,s))ans.push_back(it);
        }
        return ans;
    }
};