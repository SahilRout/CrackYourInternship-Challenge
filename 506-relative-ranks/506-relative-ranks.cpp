class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        map<int,int> mp;
        int i=0;
        for(auto it : score)
        {
            mp[it]=i;
            i++;
        }
        sort(score.begin(),score.end(),greater<int>());
        for(int i=0;i<3&&i<n;i++)
        {
            int idx=mp[score[i]];
            if(i==0)ans[idx]="Gold Medal";
            if(i==1)ans[idx]="Silver Medal";
            if(i==2)ans[idx]="Bronze Medal";
        }
        for(int i=3;i<n;i++)
        {
            ans[mp[score[i]]]=to_string(i+1);
        }
        return ans;
    }
};