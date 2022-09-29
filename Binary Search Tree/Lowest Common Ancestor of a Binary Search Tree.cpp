/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
    TreeNode*solve(TreeNode* root, TreeNode* greater, TreeNode* smaller)
    {
        if(root==NULL) return NULL;
        
        if(root==greater || root==smaller)
            return root;
        
        if(greater->val>=root->val && smaller->val<=root->val)
        {
            TreeNode*l = solve(root->left,greater,smaller);
            TreeNode*r = solve(root->right,greater,smaller);
            
            if(l==NULL && r==NULL)
            {
                return NULL;
            }
            
            else if(l==NULL)
            {
                return r;
            }
            
           else if(r==NULL)
            {
                return l;
            }
              
            return root;
        }
        
        
        else if(greater->val>=root->val && smaller->val>=root->val)
        {
            TreeNode*r = solve(root->right,greater,smaller);
            
            if(r==NULL)
            {
                return NULL;
            }
            
            return r;
            
        }
        
        else if(greater->val<=root->val && smaller->val<=root->val)
        {
            TreeNode*l = solve(root->left,greater,smaller);
            
            if(l==NULL)
            {
                return NULL;
            }
            
            return l;
            
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*greater;
        TreeNode*smaller;
        
        if(p->val>q->val)
        {
            greater = p;
            smaller = q;
        }
        
        else{
            greater = q;
            smaller = p;
        }
        
        return solve(root,greater,smaller);
        
        
            
    }
};
