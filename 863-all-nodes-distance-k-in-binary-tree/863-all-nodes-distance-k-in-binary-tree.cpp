/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> par;
    void solve(TreeNode* root )
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                par[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                par[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root);
        unordered_map<TreeNode* ,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(level==k)break;
            while(sz--)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&!vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                 if(curr->right&&!vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(par[curr]&&!vis[par[curr]])
                {
                    q.push(par[curr]);
                    vis[par[curr]]=true;
                }
                
            }
             level++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};