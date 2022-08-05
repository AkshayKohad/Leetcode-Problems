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
    
    int res = 0;
    
    void solve(TreeNode*root,int ans)
    {
        
        int result = ans*10 + root->val;
        
        if(root->left==NULL && root->right==NULL)
        {
            res += result;
        }
        
        
        if(root->left!=NULL)
        {   
            solve(root->left,result);
        }
        
        if(root->right!=NULL)
        {
            solve(root->right,result);
        }
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return res;
    }
};
