class Solution {
    void dfs(TreeNode* &root, int &sum) 
    {
        if(!root) return;
        dfs(root -> right, sum);
        root -> val = sum += root -> val;
        dfs(root -> left, sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
