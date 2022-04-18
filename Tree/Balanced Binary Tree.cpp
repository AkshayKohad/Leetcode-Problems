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
    
    
    int solve(TreeNode*root,int &flag)
    {
        if(root==NULL)
            return 0;
        
        int left = 1+solve(root->left,flag);
        
        if(flag==0)
            return 0;
        
        int right = 1+solve(root->right,flag);
        
        if(flag==0)
            return 0;
        
        int diff = abs(left-right);
        
        if(diff>1)
        {
            flag=0;
            return 0;
        }
        
        return max(left,right);
        
        
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int flag = 1;
         solve(root,flag);
        
        if(flag==0)
            return false;
        
        return true;
        
    }
};
