class Solution {
public:
    bool check(string s)
    {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty())return false;
                st.pop();
            }
        }
        
        return st.empty()?true:false;
    }
    vector<string> res;
    void solve(int n1,int n2,string ans)
    {
        if(n1==0&&n2==0){
            if(check(ans)){
                res.push_back(ans);
            }
            return;
        }
        if(n1==0)
        {
            solve(n1,n2-1,ans+')');
        }
        else if(n2==0)
        {
            solve(n1-1,n2,ans+'(');
        }
        else{
                        solve(n1,n2-1,ans+')');
                        solve(n1-1,n2,ans+'(');
            
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return res;
    }
};