/*
    Time Complexity : O(2^N)
    Space Complexity : O(N)

    Where 'N' is the number of students.
*/

#include <climits>
int ans = INT_MAX;
int tugOfWarHelper(int i, int subsetSum, int cnt, int totalSum, vector<int> &arr, int n)
{
    // base case
    if (i == n || cnt >= (n / 2))
    {
        if (cnt == (n / 2))
        {
            ans = min(ans, abs(totalSum - 2 * subsetSum));
        }
        return;
    }

    tugOfWarHelper(i + 1, subsetSum, cnt, totalSum, arr, n);

    tugOfWarHelper(i + 1, subsetSum + arr[i], cnt + 1, totalSum, arr, n);
}

int tugOfWar(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    // call the recursive function
    tugOfWarHelper(0, 0, 0, totalSum, arr, n);

    return ans;
}