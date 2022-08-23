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
    int ans=INT_MIN;
    int solve(TreeNode* root)
    {
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        ans=max(ans,l+r+1);  
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans-1;
    }
};