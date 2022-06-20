struct comp{
    bool operator()(string &a,string &b){
    return a.length()>b.length();
    }
};

class Solution {
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st;
        int ans = 0;
        
        sort(words.begin(),words.end(),comp());
        for(auto w : words)
        {
            int l = w.size();
            if(st.count(w + '#') > 0)
                continue;
            for(int i = l-1; i >= 0; i--)
            {
                
                string s = w.substr(i,l-i);
                s = s + '#';
                if(st.count(s) == 0)
                {
                    st.insert(s);
                }
            }
            ans += l+1;
            
        }
        return ans;
    }
};