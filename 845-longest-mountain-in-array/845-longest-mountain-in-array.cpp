class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            {
                int j=i;
                int cnt=1;
                while(j>0&&arr[j]>arr[j-1])
                {
                    j--;
                    cnt++;
                }
                j=i;
                while(j<n-1&&arr[j]>arr[j+1])
                {
                    j++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
            
        }
        
        return ans;
    }
};