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
    int maxLevelSum(TreeNode* root) {
        int sum=INT_MIN;
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        int x=1;
        while(!q.empty())
        {
            int tSum=0;
            int n=q.size();
            while(n--)
            {
                tSum+=q.front()->val;
                TreeNode* t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            if(sum<tSum)
            {
                sum=tSum;
                level=x;
            }
            x++;
        }
        return level;
    }
};