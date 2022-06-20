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
    
    void solve(TreeNode*root,int &k,int &res)
    {
        if(root==NULL)
            return;
        
        if(k==0)
            return;
        
        solve(root->left,k,res);
        if(k==0)
            return;
        k--;
        if(k==0)
        {
            res = root->val;
            return;
        }
        
        solve(root->right,k,res);
            
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        solve(root,k,res);
        return res;
    }
};
