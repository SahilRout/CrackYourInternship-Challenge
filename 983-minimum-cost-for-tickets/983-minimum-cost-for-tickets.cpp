class Solution {
public:
    int dp[366];
    int solve(vector<int> const &days,vector<int>const &costs,int idx)
    {
        int n=days.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int cost_day=costs[0]+solve(days,costs,idx+1);
        
        int i=idx+1;
        while(i<n&&days[i]-days[idx]<7)i++;
        int cost_week=costs[1]+solve(days,costs,i);
        i=idx+1;
        while(i<n&&days[i]-days[idx]<30)i++;
        int cost_month=costs[2]+solve(days,costs,i);
        
        return dp[idx]=min({cost_day,cost_week,cost_month});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        sort(days.begin(),days.end());
        return solve(days,costs,0);
    }
};