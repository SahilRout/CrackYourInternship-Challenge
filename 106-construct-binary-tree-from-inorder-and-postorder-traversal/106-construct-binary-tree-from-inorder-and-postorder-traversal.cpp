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
    map<int,int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>&inorder,int inst,int inen,vector<int>&postorder,int post,int poen)
    {
        if(inst>inen||post>poen)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[poen]);
        int inRoot=mp[postorder[poen]];
        int numsLeft=inRoot-inst;
        root->left=build(inorder,inst,inRoot-1,postorder,post,post+numsLeft-1);
        
        root->right=          build(inorder,inRoot+1,inen,postorder,post+numsLeft,poen-1);
        return root;
    }
};