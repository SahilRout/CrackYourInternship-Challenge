class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<string,int> mp;
        for(auto it : grid)
        {
            string s="";
            for(int i=0;i<it.size();i++)
            {
                s+=to_string(it[i]);
                s+='#';
            }
           // cout<<s<<endl;
            mp[s]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<n;j++)
            {
                s+=to_string(grid[j][i]);
                s+='#';
            }
            if(mp.find(s)!=mp.end())
            {
                ans+=mp[s];
            }
        }
        
        return ans;
    }
};