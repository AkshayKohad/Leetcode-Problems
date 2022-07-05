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
    
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp)
    {
        if(root==NULL)
            return 0;
        
        
        if(mp.find(root)!=mp.end())
            return mp[root];
        
        int lr=0,lrl=0,lrr=0,ll=0,lll=0,llr=0;
        
        int rl=0,rr=0,rlr=0,rll=0,rrr=0,rrl=0;
        
        if(root->left!=NULL)
        {
            TreeNode*p = root->left;
             lr = solve(p->right,mp);
            
            ll = solve(p->left,mp);
            
            if(root->left->right!=NULL)
            {
                TreeNode*q = root->left->right;
                lrl = solve(q->left,mp);
                
                lrr = solve(q->right,mp);
            }
            
            if(root->left->left!=NULL)
            {
                TreeNode*q = root->left->left;
                
                lll = solve(q->left,mp);
                
                llr = solve(q->right,mp);
            }
            
        }
        
        
        if(root->right!=NULL)
        {
           TreeNode*p = root->right;
            
            rl = solve(p->left,mp);
            
            rr = solve(p->right,mp);
            
            if(root->right->right!=NULL)
            {
                 TreeNode*q = root->right->right;
                
                rrr = solve(q->right,mp);
                
                rrl = solve(q->left,mp);
            }
            
            if(root->right->left!=NULL)
            {
                 TreeNode*q = root->right->left;
               rlr = solve(q->right,mp);
                
                rll = solve(q->left,mp);
            }
        }
        
        
        int ans1 = max(ll,lll+llr);
        int ans2 = max(lr,lrl+lrr);
        int ans3 = max(rl,rll+rlr);
        int ans4 = max(rr,rrl+rrr);
        
        
        int res1 =  root->val + ans1 + ans2 + ans3 + ans4;
        
        int res2 = solve(root->left,mp) + solve(root->right,mp);
        
        mp[root] = max(res1,res2);
        return max(res1,res2);
        
        
    }
    int rob(TreeNode* root) {
        
        
        unordered_map<TreeNode*,int>mp;
       return solve(root,mp);
    }
};
