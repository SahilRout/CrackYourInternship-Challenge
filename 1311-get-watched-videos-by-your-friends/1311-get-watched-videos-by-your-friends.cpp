class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> ans;
        map<string,int> mp;
        queue<int> q;
        q.push(id);
        int lvl=1;
        vector<int> vis(friends.size(),0);
        vis[id]=1;
        while(!q.empty())
        {
            int s=q.size();
            if(level==0)break;
            ans.clear();
            while(s--)
            {
                int x=q.front();
                q.pop();
                for(auto it : friends[x]){
                    if(!vis[it]){
                       // ans.push_back(it)
                               vis[it]=1;
                        q.push(it);
                    }
                }
            }
            level--;
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it : watchedVideos[x])mp[it]++;
        }
            vector<pair<int,string>>res;
        for(auto x:mp)
        {
              res.push_back({x.second,x.first});
        }
        sort(res.begin(),res.end());
       
        vector<string>fin;
        for(auto x:res)
        {
            fin.push_back(x.second);
        }
        return fin;
    }
};