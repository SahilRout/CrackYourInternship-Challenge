class Solution {
public:
    int solve(TreeNode* root,int &ans)
    {
        if(root==NULL) return 0;
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        int res=l+r+1;
        ans=max(res,ans);
        
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans-1;
    }
};