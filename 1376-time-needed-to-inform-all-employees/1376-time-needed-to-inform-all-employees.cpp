class Solution {
public:
    int dfs(int i,vector<int> &manager,vector<int> &informtime)
    {
        if(manager[i]!=-1)
        {
            informtime[i]+=dfs(manager[i],manager,informtime);
            manager[i]=-1;
        }
        return informtime[i];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dfs(i,manager,informTime));
        }
        return ans;
    }
};