// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& nums, int target,int n)
    {
        if(n==0&&target==0)return 1;
        if(n==0)return 0;
        return solve(nums,target-nums[n-1],n-1)+solve(nums,target+nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>&nums ,int target) {
        return solve(nums,target,nums.size());
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends