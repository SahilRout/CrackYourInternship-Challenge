class Solution {
public:
    int dp[501][501];
int maxSatisfaction(vector<int>& s) {
    if(s.size()==1)
    {
      if(s[0]>0)
        return s[0];
      else
        return 0;
    }
    sort(s.begin(),s.end());
    memset(dp,-1,sizeof dp);
    return solve(s,0,1);
}
int solve(vector<int>&s,int st,int time){
 if(st==s.size()-1)
   return time*s[st];
 if(st>s.size())
   return 0;
 if(dp[st][time]!=-1)
   return dp[st][time];
 int ans1=time*s[st]+solve(s,st+1,time+1);
 int ans2=solve(s,st+1,time);
 return dp[st][time]=max(0,max(ans1,ans2));
 }
};