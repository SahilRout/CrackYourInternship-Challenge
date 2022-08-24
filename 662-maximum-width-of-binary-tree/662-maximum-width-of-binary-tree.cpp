class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int cnt=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=1;
        while(!q.empty())
        {
            int currMin=q.front().second;
            int size=q.size();
            int left=0;
            int right=0;
            for(int i=0;i<size;i++)
            {
                int idx=q.front().second-currMin;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)left=idx;
                if(i==size-1)right=idx;
                if(node->left)q.push({node->left,(2LL*idx)+1});
                if(node->right)q.push({node->right,(2LL*idx)+2});
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};