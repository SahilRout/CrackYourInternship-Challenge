class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
                 queue<vector<int>> q;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        q.push({0,0,k,0});
        int ans=0;
        while(!q.empty())
        {
                int r=q.front()[0];
                int c=q.front()[1];
                int h=q.front()[2];
                ans=q.front()[3];
                q.pop();
                if((r>=0&&r<n)&&(c>=0&&c<m))
                {
                    if(r==n-1&&c==m-1)
                    {
                        return ans;
                    }
                    if(mat[r][c]==1)
                    {
                        if(h>0)
                        {
                           // mat[r][c]=0;
                            h--;
                        }
                        else continue;
                    }
                    if(vis[r][c]!=-1&&vis[r][c]>=h)continue;
                    //mat[r][c]=1;
                    vis[r][c]=h;
                    q.push({r+1,c,h,ans+1});
                    q.push({r-1,c,h,ans+1});
                    q.push({r,c+1,h,ans+1});
                    q.push({r,c-1,h,ans+1});
                }
        }
        return -1;
    }
};