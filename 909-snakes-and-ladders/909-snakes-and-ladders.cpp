class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis((n*n)+1,0);
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
                    int r=n-(nextPos-1)/n-1;
                    int c=(nextPos-1)%n;
                    if(r%2==n%2)
                    {
                        c=n-c-1;
                    }
                    if(!vis[nextPos])
                    {
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