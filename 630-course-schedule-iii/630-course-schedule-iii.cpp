class Solution {
public:
    static bool myComp(vector<int> &a,vector<int> &b)
    {
        return (a[1]<b[1]);
    }
    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),myComp);
       // int res=0;
        int time=0;
        priority_queue<int> pq;
        for(auto it : arr)
        {
            int dur=it[0],end=it[1];
            if(dur+time<=end)
            {
                time+=dur;
                pq.push(dur);
            }
            else if(pq.size()&&pq.top()>dur)
            {
                time+=dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};