class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                string temp="";
                while(!st.empty()&&st.top()!='[')
                {
                    char x=st.top();
                    st.pop();
                    temp=x+temp;
                }
                st.pop();
                string num="";
                while(!st.empty()&&isdigit(st.top()))
                {
                    char x=st.top();
                    st.pop();
                    num=x+num;
                }
                int x=stoi(num);
                string s="";
                while(x--)
                {
                    for(auto it : temp)st.push(it);
                }
                    
            }
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty())
        {
            char a=st.top();
            ans+=a;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};