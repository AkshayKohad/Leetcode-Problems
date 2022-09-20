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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        
        queue<TreeNode*>q;
        
        q.push(root);
        int level = 0;
        while(q.empty()==false)
        {
            
           
            int count = q.size();
            
            vector<TreeNode*>a;
            
            while(count--)
            {
                TreeNode*cur = q.front();
                q.pop();
                
                if(cur->left!=NULL)
                {
                    if(level%2==0)
                    {
                        a.push_back(cur->left);
                    }
                    
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL)
                {
                    if(level%2==0)
                    {
                        a.push_back(cur->right);
                    }
                    
                    q.push(cur->right);
                }
            }
            
            level++;
             if(level%2==1)
            {
                int i=0;
                 int j=a.size()-1;
                 
                 while(i<j)
                 {
                     int t = a[i]->val;
                     a[i]->val = a[j]->val;
                     a[j]->val = t;
                     
                     i++;
                     j--;
                 }
            }
            
        }
        
        return root;
        
    }
};
