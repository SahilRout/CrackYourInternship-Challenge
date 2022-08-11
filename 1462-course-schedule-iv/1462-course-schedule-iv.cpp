class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(n,vector<bool>(n,0));
        for(auto it : pre)
        {
            reachable[it[0]][it[1]]=1;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    reachable[i][j]=reachable[i][j]||(reachable[i][k]&&reachable[k][j]);
                }
            }
        }
         cout<<1<<endl;
        vector<bool> ans;
        for(auto it : queries)
        {
            ans.push_back(reachable[it[0]][it[1]]);
        }
        return ans;
    }
};