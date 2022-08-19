class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i=0;i<cuboids.size();i++)
        {
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        vector<int> lis(n,0);
        lis[0]=cuboids[0][2];
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            lis[i]=cuboids[i][2];
            for(int j=0;j<i;j++)
            {
                if(cuboids[i][0]>=cuboids[j][0]&&cuboids[i][1]>=cuboids[j][1]&&cuboids[i][2]>=cuboids[j][2])
                {
                    lis[i]=max(lis[i],lis[j]+cuboids[i][2]);
                }
            }
            ans=max(ans,lis[i]);
        }
        
        return ans;
    }
};