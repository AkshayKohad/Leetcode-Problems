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
    void solve(TreeNode*root,int &ans)
    {
        if(root==NULL)
            return;
        
        if(root->val%2==0)
        {
            int lr=0,ll=0,rl=0,rr=0;
            if(root->left!=NULL)
            {
                TreeNode*t = root->left;
                
                if(t->right!=NULL)
                  lr = t->right->val;
                
                
                if(t->left!=NULL)
                  ll = t->left->val;
                    
                
            }
            
            
            if(root->right!=NULL)
            {
                TreeNode*t = root->right;
                
                if(t->right!=NULL)
                    rr = t->right->val;
                
                if(t->left!=NULL)
                    rl = t->left->val;
            }
              
            ans = ans + ll + lr + rl + rr;
        }   
        
        solve(root->left,ans);
        solve(root->right,ans);
        
        return;
    }
    
    
    int sumEvenGrandparent(TreeNode* root) {
        
        int ans = 0;
        solve(root,ans);
        
        return ans;
    }
};
