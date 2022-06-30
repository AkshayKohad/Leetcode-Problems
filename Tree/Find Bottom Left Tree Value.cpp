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
    int findBottomLeftValue(TreeNode* root) {
        
        int x = 0;
        int y = 0;
        
        TreeNode*res = root;
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        while(q.empty()==false)
        {
            pair<TreeNode*,pair<int,int>>curr = q.front();
            q.pop();
            
            TreeNode*nd = curr.first;
            
            int x_point = curr.second.first;
            int y_point = curr.second.second; 
            
            if(y_point == y)
            {
                if(x_point<x)
                {
                    y = y_point;
                    x = x_point;
                    res = nd;
                }
            }
            
            
            else if(y_point > y)
            {
                 y = y_point;
                    x = x_point;
                    res = nd;
            }
            
            if(nd->left!=NULL)
            {
                q.push({nd->left,{x_point-1,y_point+1}});
            }
            
            if(nd->right!=NULL)
            {
                q.push({nd->right,{x_point+1,y_point+1}});
            }
            
        }
        
        
        return res->val;
    }
};
