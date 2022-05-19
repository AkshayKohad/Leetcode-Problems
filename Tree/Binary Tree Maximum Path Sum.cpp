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
    
    int solve(TreeNode*root,int &res)
    {
        if(root==NULL)
            return 0;
        
        int lh = solve(root->left,res);
        
        int rh = solve(root->right,res);
        
        int ans = root->val;
        
        int ans2 = root->val + max(lh,rh);
        
        int ans3 = root->val + lh + rh;
        
        
        res = max(res,ans3);
        res = max(res,ans2);
        res = max(res,ans);
        
        return max(ans,ans2);
        
        
    }
    int maxPathSum(TreeNode* root) {
     int res = root->val;
        
        solve(root,res);
        
        return res;
    }
};
