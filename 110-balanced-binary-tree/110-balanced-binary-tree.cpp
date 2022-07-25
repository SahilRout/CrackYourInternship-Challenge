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
    bool flag=true;
    int solve(TreeNode* root)
    {
        if(!root)return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        if(abs(r-l)>1){
            flag=false;
        }
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return flag;
    }
};