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
    vector<TreeNode*> ans;
    bool solve(TreeNode* root,TreeNode* p)
    {
        if(!root)return false;
        ans.push_back(root);
        if(root==p)return true;
       if(solve(root->left,p)||
        solve(root->right,p)) return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p);
        vector<TreeNode*> a=ans;
        ans.clear();
        solve(root,q);
        vector<TreeNode*> b=ans;
        int i=0;
        for(i=0;i<min(a.size(),b.size());i++)
        {
            if(a[i]!=b[i])return a[i-1];
        }
        return a[i-1];
    }
};