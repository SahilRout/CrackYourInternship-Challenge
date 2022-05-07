class Solution {
public:
    int ans=0;
    void solve(vector<int> arr,int n,int idx)
    {
        if(idx>n)ans++;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]==0&&(i%idx==0||idx%i==0))
               {
                   arr[i]=idx;
                   solve(arr,n,idx+1);
                   arr[i]=0;
               }      
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n+1,0);
        solve(arr,n,1);
        return ans;
    }
};