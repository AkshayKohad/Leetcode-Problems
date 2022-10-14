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
    
    void solve(TreeNode*root,int targetSum,vector<int>&ans,vector<vector<int>>&res)
    {
        if(root==NULL)
        {
            
            return;
        }
        
        ans.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL)
        {
           if(targetSum-root->val==0)
           {
               res.push_back(ans);
           }
        }
        
        else{
        solve(root->left,targetSum-root->val,ans,res);
        
        solve(root->right,targetSum-root->val,ans,res);
        
        }
        ans.pop_back();
        
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    
        if(root==NULL)
            return {};
        
        vector<vector<int>>res;
        vector<int>ans;
        
        solve(root,targetSum,ans,res);
        
        return res;
    }
};
