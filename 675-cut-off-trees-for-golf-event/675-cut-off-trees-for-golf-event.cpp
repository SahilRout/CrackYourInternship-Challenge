class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int cutOffTree(vector<vector<int>>& forest) {
         vector<vector<int>> orig(forest.begin(),forest.end());
         vector<int> p;
        int m=forest.size();
        int n=forest[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(forest[i][j]>1) p.push_back(forest[i][j]);
            }
        }
        sort(p.begin(),p.end());
        int ans=0;
        int x=0;
        int y=0;
        int ans1=0;
        int vis=0;
        int flag=0;
        for(int i=0;i<p.size();i++)
        {
            vis=0;
            int val=p[i];
            queue<pair<int,int>> q;
            q.push({x,y});
            while(!q.empty())
            {
                if(val==orig[q.front().first][q.front().second])
                {
                    x=q.front().first;
                    y=q.front().second;
                    vis=1;
                    break;
                }
                ans1++;
                flag=0;
                int size=q.size();
                while(size--)
                {
                    auto it = q.front();
                    q.pop();
                    x=it.first;
                    y=it.second;
                    for(int j=0;j<4;j++)
                    {
                        int newx=x+dx[j];
                        int newy=y+dy[j];
                        if(newx>=0&&newx<m&&newy>=0&&newy<n&&forest[newx][newy]>=1)
                        {
                            if(val==orig[newx][newy])
                            {
                                vis=1;
                                x=newx;
                                y=newy;
                                flag=1;
                                break;
                            }
                            q.push({newx,newy});
                            forest[newx][newy]=0;
                        }
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            ans+=ans1;
            flag=0;
            forest=orig;
            ans1=0;
            if(vis==0)return -1;
        }
        
        return ans;
    }
};