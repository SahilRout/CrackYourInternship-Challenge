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
     unordered_map<int,int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
    TreeNode* build(vector<int>&preorder,int prest,int preen,vector<int>&inorder,int inst,int inen)
    {
        if(prest>preen||inst>inen)return NULL;
        TreeNode* root=new TreeNode(preorder[prest]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inst;
        root->left=build(preorder,prest+1,prest+numsLeft,inorder,inst,inRoot-1);
        root->right=build(preorder,prest+numsLeft+1,preen,inorder,inRoot+1,inen);
        return root;
    }
};