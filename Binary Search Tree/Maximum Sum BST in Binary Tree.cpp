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

class NodeValue{
  
    public:
        int maxNode,minNode,maxSum;
    
    NodeValue(int maxNode,int minNode,int maxSum)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSum = maxSum;
    }
    
};

NodeValue solve(TreeNode*root,int &res)
{
    if(root==NULL)
    {
        return  NodeValue(INT_MIN,INT_MAX,0);
    }
    
    auto left = solve(root->left,res);
    
    auto right = solve(root->right,res);
    
    
    if(left.maxNode < root->val && root->val < right.minNode)
    {
        int ans = right.maxSum+left.maxSum+root->val;
       
        res = max(res,ans);
        
        int lval = right.maxNode;
        int rval = left.minNode;
        if(root->right==NULL)
        {
            lval = root->val;
        }
        
        if(root->left==NULL)
        {
            rval = root->val;
        }
        return  NodeValue(lval,rval,ans);
    }
    
    
        return  NodeValue(INT_MAX,INT_MIN,0);
    
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        
        int res = 0;
        solve(root,res);
        
        return res;
        
    }
};
