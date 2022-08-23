/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int flag=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> t;
            while(sz--)
            {
                TreeNode* node=q.front();
                q.pop();
                t.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(flag)
            {
                reverse(t.begin(),t.end());
                flag=0;
            }
            else flag=1;
            ans.push_back(t);
        }
        
        return ans;
    }
};