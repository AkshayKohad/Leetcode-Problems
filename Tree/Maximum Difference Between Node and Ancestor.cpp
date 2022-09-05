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
    void dfs(TreeNode*root,int mini,int maxi,int &res)
    {
        if(root==NULL)
        {
            res = max(res,abs(maxi-mini));
            return;
        }
        
        int  t_mini = mini;
        
        int t_maxi = maxi;
        
        t_mini = min(mini,root->val);
        
        t_maxi = max(maxi,root->val);
        
        dfs(root->left,t_mini,t_maxi,res);
        
        dfs(root->right,t_mini,t_maxi,res);
        
        
        return;
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
    
         int res = 0;
        dfs(root,mini,maxi,res);
        
        return res;
    }
};
