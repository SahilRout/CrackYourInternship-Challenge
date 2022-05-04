class Solution
{
public:
    bool solve(int arr[], int n, int sum, int Tsum, int i, vector<vector<int>> &dp)
    {
        if (Tsum - sum == sum)
        {
            return true;
        }
        if (dp[i][sum] != -1)
            return dp[i][sum];
        if (i == n)
        {
            return false;
        }
        return dp[i][sum] = (solve(arr, n, sum + arr[i], Tsum, i + 1, dp) || solve(arr, n, sum, Tsum, i + 1, dp));
    }
    int equalPartition(int N, int arr[])
    {
        int Tsum = 0;
        for (int i = 0; i < N; i++)
            Tsum += arr[i];
        vector<vector<int>> dp(N + 1, vector<int>(Tsum + 1, -1));
        return solve(arr, N, 0, Tsum, 0, dp);
    }
};