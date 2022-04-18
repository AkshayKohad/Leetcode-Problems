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
    bool isCousins(TreeNode* root, int x, int y) {
        
        
        int levelx;
        int parentx;
        int levely;
        int parenty;
        
        queue<pair<TreeNode*,TreeNode*>>q;
        
        q.push({root,NULL});
        int level=0;
        q.push({NULL,NULL});
        
        while(q.size()>1)
        {
           TreeNode* curr = q.front().first;
            TreeNode* par = q.front().second;
            q.pop();
            
           
            
            if(curr==NULL)
            {
                q.push({NULL,NULL});
                level++;
                continue;
            }
            
            if(curr->val==x)
            {
                levelx = level;
                if(par==NULL)
                parentx =  -1;
                
                else{
                    parentx = par->val;
                }
            }
            
            else  if(curr->val==y)
            {
                levely = level;
                if(par==NULL)
                parenty =  -1;
                
                else{
                    parenty = par->val;
                }
            }
            
            
            if(curr->left!=NULL)
            {
                q.push({curr->left,curr});
            }
            
            if(curr->right!=NULL)
            {
                q.push({curr->right,curr});
            }
        }
        
        
        if(levelx == levely && parentx!=parenty)
            return true;
        
        
        return false;
    }
};
