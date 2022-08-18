class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<int>pq;
        for(auto it:mp)
        {
          pq.push(it.second);
        }
        int count=0;
        int res=0;
        while(count<n/2)
        {
           count +=pq.top();
            pq.pop();
            res++;
               
        }
        return res;
    }
};