class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        vector<int>t1,t2;
        for(auto it : nums1)s1.insert(it);
        for(auto it : nums2)s2.insert(it);
        for(auto it : s1)
        {
            if(s2.find(it)!=s2.end())
            {
                continue;
            }
            else t1.push_back(it);
        }
        for(auto it : s2)
        {
            if(s1.find(it)!=s1.end())
            {
                continue;
            }
            else t2.push_back(it);
        }
        vector<vector<int>> ans;
        ans.push_back(t1);
        ans.push_back(t2);
        return ans;
    }
};