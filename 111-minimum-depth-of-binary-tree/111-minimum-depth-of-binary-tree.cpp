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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            level++;
            int sz=q.size();
            while(sz--)
            {
                            TreeNode* node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            if(!node->left&&!node->right)return level;
            }
        }
        return level;
    }
};