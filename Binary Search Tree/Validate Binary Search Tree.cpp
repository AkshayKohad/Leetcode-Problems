class Solution {
public:
   
    bool solve(TreeNode*root,long int min_value,long int max_value)
    {
        if(root==NULL)
            return true;
        
        if(root->val >= max_value || root->val <= min_value)
            return false;
        
        
        return solve(root->left,min_value,root->val) && solve(root->right,root->val,max_value);
    }
    
    bool isValidBST(TreeNode* root) {
       long  int min_value = LONG_MIN;
       long int max_value = LONG_MAX;
        
        return solve(root,min_value,max_value);
    }
};
