class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> arr,int target,int i,vector<int> temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int idx=i;idx<arr.size();idx++)
        {
            if(idx>i&&arr[idx]==arr[idx-1])continue;
            if(arr[idx]>target) break;
            temp.push_back(arr[idx]);
            solve(arr,target-arr[idx],idx+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,target,0,temp);
        return ans;
    }
};
