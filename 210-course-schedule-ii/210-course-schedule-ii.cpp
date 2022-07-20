class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                queue<int> q;
        vector<int> indegree(numCourses,0);
         vector<vector<int>> adj(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
         adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
           indegree[ prerequisites[i][0]]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        if(cnt!=numCourses)
        {
            ans.clear();
        }
        
        return ans;
    }
};