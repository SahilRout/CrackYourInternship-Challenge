class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis((n*n)+1,0);
        map<int,pair<int,int>> mp;
        int x=1;
        bool flag=true;
        for(int i=board.size()-1;i>=0;i--)
        {
            if(!flag)
            {
            for(int j=board[0].size()-1;j>=0;j--)
            {
               cout<<x<<" ";
                mp[x].first=i;
                mp[x].second=j;
                x++;
            }
                flag=true;
            }
            else{
                for(int j=0;j<board[0].size();j++)
            {
                    cout<<x<<" ";
                mp[x].first=i;
                mp[x].second=j;
                x++;
            }
                flag=false;
            }
           cout<<endl;
        }
        queue<int> q;
        q.push(1);
        vis[1]=1;
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int currPos=q.front();
                q.pop();
                if(currPos==n*n)return ans;
                for(int i=1;i<=6;i++)
                {
                    int nextPos=currPos+i;
                    if(nextPos>n*n)break;
                    int r=mp[nextPos].first;
                    int c=mp[nextPos].second;
                    if(!vis[nextPos])
                    {
                       // cout<<board[r][c]<<" ";
                        vis[nextPos]=1;
                        if(board[r][c]!=-1)q.push(board[r][c]);
                        else q.push(nextPos);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};