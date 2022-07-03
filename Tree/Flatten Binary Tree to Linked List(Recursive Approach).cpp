class Solution {
public:
    
    TreeNode*prev = NULL;
    
    void solve(TreeNode*root)
    {
        if(root==NULL)
            return;
        
        solve(root->right);
        solve(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
    
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        
         solve(root);
        
    }
};
