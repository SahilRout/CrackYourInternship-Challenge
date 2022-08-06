class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> vis(forbidden.begin(),forbidden.end());
        queue<pair<int,bool>> q;
        q.push({0,true});
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto curr=q.front();
                q.pop();
                int num=curr.first;
                if(num==x)return ans;
                if(vis.find(num)!=vis.end())continue;
                vis.insert(num);
                if(curr.second==true&&num-b>=0)q.push({num-b,false});
                if(num<=2000+b)q.push({num+a,true});
            }
            ans++;
        }
        
        return -1;
    }
};