class Solution {
public:
   static bool compare(string s1,string s2)
   {
       return s1.size()<s2.size();
   }
    bool check(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1)return false;
        int ft=0;
        int sd=0;
        while(ft<s1.size())
        {
            if(s1[ft]==s2[sd]){
                ft++;
                sd++;
            }
            else ft++;
        }
        if(ft==s1.size()&&sd==s2.size())return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n=words.size();
        vector<int> dp(n,1);
        int len=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j])&&dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                    len=max(len,dp[i]);
                }
            }
        }
        
        return len;
    }
};