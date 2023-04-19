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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        //parent-sumchild
        unordered_map<TreeNode*,int>parent_childsum;
        //child-parent
        unordered_map<TreeNode*,TreeNode*>child_parent;
        //depth-sum
        unordered_map<int,int>depth_sum;
        
        queue<TreeNode*>q;
        
        TreeNode*pre_root = new TreeNode(-1);
        int level = 0;
        q.push(root);
        while(q.empty()==false)
        {
            int size = q.size();
            
            while(size--)
            {
                TreeNode*cur = q.front();
                q.pop();
                
                depth_sum[level] += cur->val;
                
                if(cur->left!=NULL)
                {
                    child_parent[cur->left] = cur;
                    parent_childsum[cur] += cur->left->val;
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL)
                {
                    child_parent[cur->right] = cur;
                    parent_childsum[cur] += cur->right->val;
                    q.push(cur->right);
                }
                
                
            }
            level++;
        }
        
        root->val = 0;
        
        q.push(root);
        level=0;
        while(q.empty()==false)
        {
            int size = q.size();
            
            while(size--)
            {
                TreeNode*cur = q.front();
                q.pop();
                
                if(cur!=root)
                {
                 cur->val = depth_sum[level] - parent_childsum[child_parent[cur]];
                }
                
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                }
                
                
            }
            level++;
        }
        
        return root;
        
    }
};
