class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n-1;)
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
                while(i<n-1&&arr[i]>arr[i+1])
                {
                    i++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
            else i++;
            
        }
        
        return ans;
    }
};