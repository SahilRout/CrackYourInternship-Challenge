class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        map<char,int> mp;
        int j=0;
        int i=0;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end()&&mp[s[j]]>=i) 
            {
                i=mp[s[j]]+1;
            }
                 ans=max(ans,j-i+1);
                mp[s[j]]=j;
                j++;
        }
        
        return ans;   
    }
};