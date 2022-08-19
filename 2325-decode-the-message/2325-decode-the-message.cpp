class Solution {
public:
    string decodeMessage(string s, string ms) {
        map<char,char> mp;
        char c='a';
        int n=s.size();
        int m=ms.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')continue;
            if(mp.count(s[i])>0)continue;
            mp[s[i]]=c;
            c++;
        }
        string ans="";
        for(int i=0;i<m;i++)
        {
            if(ms[i]==' ')ans+=" ";
            else{
                ans+=mp[ms[i]];
            }
        }
        return ans;
    }
};