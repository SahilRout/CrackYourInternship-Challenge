class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       // if(arr.size()==1)return 1;
        int count=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(arr[i],maxi);
            if(i==maxi)count++;
        } 
       // if(count==0)return 1;
        return count;
    }
};