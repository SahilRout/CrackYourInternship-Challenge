class Solution
{
public:
    bool solve(int a[], int n, vector<int> &vis, int idx, int k, int subsetSum, int curr_num, int target)
    {
        if (k == 1)
            return true;
        if (subsetSum == target)
        {
            return solve(a, n, vis, 0, k - 1, 0, 0, target);
        }
        for (int i = idx; i < n; i++)
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                if (solve(a, n, vis, i + 1, k, subsetSum + a[i], curr_num++, target))
                    return true;
                vis[i] = 0;
            }
        }

        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        if (k <= 0 || sum % k != 0)
            return false;
        vector<int> vis(n, 0);
        return solve(a, n, vis, 0, k, 0, 0, sum / k);
    }
};
