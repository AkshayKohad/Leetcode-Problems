class Solution {
public:
    TreeNode*solve(vector<int>&preorder,int &i,int max_value)
    {
        if(i==preorder.size() || max_value<=preorder[i])
            return NULL;
        
        TreeNode*root = new TreeNode(preorder[i++]);
        
        root->left = solve(preorder,i,root->val);
        
        root->right = solve(preorder,i,max_value);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        int max_value = INT_MAX;
        
        return solve(preorder,i,max_value);
    }
};
