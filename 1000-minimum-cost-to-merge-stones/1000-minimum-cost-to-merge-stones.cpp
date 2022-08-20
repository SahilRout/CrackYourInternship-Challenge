class Solution {
public:
    int dp[31][31][31];
    int solve(int i,int j,int piles,vector<int>&pref,int &k)
    {
        if(i==j&&piles==1)return 0;
        if(i==j)return INT_MAX/4;
        if(dp[i][j][piles]!=-1)return dp[i][j][piles];
        if(piles==1)
        {
            return dp[i][j][piles]=solve(i,j,k,pref,k)+(i==0?pref[j]:pref[j]-pref[i-1]);
        }
        else{
            int cost=INT_MAX/4;
            for(int t=i;t<j;t++)
            {
                cost=min(cost,solve(i,t,1,pref,k)+solve(t+1,j,piles-1,pref,k));
            }
            return dp[i][j][piles]=cost;
        }
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0)return -1;
        int sum=0;
        memset(dp,-1,sizeof(dp));
        vector<int> pref;
        for(auto it : stones)
        {
            sum+=it;
            pref.push_back(sum);
        }
        return solve(0,n-1,1,pref,k);
    }
};