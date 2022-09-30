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
    int deepestLeavesSum(TreeNode* root) {
        
       
        queue<TreeNode*>q;
        
        q.push(root);
        
        int res = 0;
        while(q.empty()==false)
        {
            int size = q.size();
             int sum = 0;     
            while(size--)
            {
                TreeNode*cur = q.front();
                q.pop();
                
                sum += cur->val;
                
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                }
            }
            
            res = sum;
        }
        
        return res;
    }
};
