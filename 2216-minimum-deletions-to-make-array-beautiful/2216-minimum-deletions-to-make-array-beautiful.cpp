class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                p.push_back({i,i+1});
            }
        }
        int idx=0;
        int cnt=0;
        for(auto it : p)
        {
            if((it.first-idx)%2==0)
            { 
                idx++;
                cnt++;
            }
        }
        if((nums.size()-cnt)%2!=0)return cnt+1;
        return cnt;
    }
};