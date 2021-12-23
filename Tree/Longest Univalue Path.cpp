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
    
    int solution(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        
        int l = solution(root->left,ans);
        int r = solution(root->right,ans);
        
        if(root->left!=NULL && root->right!=NULL)
        {
            if(root->left->val == root->val && root->right->val == root->val)
            {
                int ans1 = 1+max(l,r);
                 ans = max(ans,l+r+2);
                return ans1;
            }
            
            else if(root->left->val == root->val || root->right->val == root->val)
            {
                if(root->left->val == root->val)
                {
                    int ans1 = max(1+l,r);
                    ans = max(ans,ans1);
                    return 1+l;
                    
                    
                }
                
                else if(root->right->val == root->val)
                {
                    int ans1 = max(l,1+r);
                    ans = max(ans,ans1);
                    return 1+r;
                }
            }
            
            else{
                return 0;
            }
        }
        
        else if(root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        
        else if(root->left==NULL)
        {
            if(root->right->val == root->val)
                {
                    int ans1 = max(l,1+r);
                    ans = max(ans,ans1);
                    return 1+r;
                }
            
            else
                return 0;
        }
        
        else if(root->right==NULL)
        {
            if(root->left->val == root->val)
                {
                    int ans1 = max(1+l,r);
                    ans = max(ans,ans1);
                    return 1+l;
                    
                    
                }
            
            else 
                return 0;
        }
        
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        solution(root,ans);
        return ans;
    }
};
