class Solution
{
public:
    // Function to find the largest number after k swaps.
    void solve(string str, int k, int idx, int n, string &ans)
    {
        //  cout<<k<<endl;
        if (k == 0)
            return;
        if (idx == n)
            return;
        char maxChar = str[idx];
        for (int i = idx + 1; i < n; i++)
        {
            if (maxChar < str[i])
                maxChar = str[i];
        }

        if (maxChar != str[idx])
        {
            k--;
            for (int i = idx + 1; i < n; i++)
            {
                if (str[i] == maxChar)
                {
                    swap(str[idx], str[i]);
                    if (ans < str)
                    {
                        ans = str;
                    }
                    solve(str, k, idx + 1, n, ans);
                    swap(str[idx], str[i]);
                }
            }
        }
        else
            solve(str, k, idx + 1, n, ans);
    }
    string findMaximumNum(string str, int k)
    {
        string ans = str;
        solve(str, k, 0, str.size(), ans);
        return ans;
    }
};