class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node)
    {
        if(color[node] == 1) return false;   // If a node is being visited & we visit again (i.e. cycle is detected), return false
        
        color[node] = 1;
        for(int neighbor: graph[node])
        {
            if(color[neighbor] == 2) continue;
            if(color[neighbor] == 1 or !dfs(graph, color, neighbor)) return false;  // If a neighbor is already visited or dfs of the neighbor return false (i.e. cycle is detected), we return false;
        }
        
        color[node] = 2;   // Otherwise, mark the node as safe & return true;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) 
    {
        vector<int> color(graph.size(), 0), result;
		
		for(int i=0; i<graph.size(); i++)
        {
            if(color[i] == 2 or dfs(graph, color, i)) // Add only if node is safe or dfs return true. DFS returns true, only when there is no cycle
                result.push_back(i);
        }
                
        return result;
    }
};