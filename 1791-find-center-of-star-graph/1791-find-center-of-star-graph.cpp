class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        int maxi=1;
        for(auto it : edges)
        {
            mp[it[0]]++;
            maxi=max(maxi,it[0]);
            mp[it[1]]++;
             maxi=max(maxi,it[1]);
        }
        for(auto it : mp)
        {
            if(it.second==maxi-1)return it.first;
        }
        
        return 1;
    }
};