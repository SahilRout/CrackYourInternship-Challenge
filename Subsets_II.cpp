class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> arr, int n, int idx, vector<int> ds)
    {
        ans.push_back(ds);
        for (int i = idx; i < n; i++)
        {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            solve(arr, n, i + 1, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> ds;
        solve(arr, arr.size(), 0, ds);
        return ans;
    }
};