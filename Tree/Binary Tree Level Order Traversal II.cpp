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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>res;
        vector<int>a;
        while(q.size()>1)
        {
            TreeNode*curr = q.front();
            q.pop();
            
            if(curr==NULL)
            {
                res.push_back(a);
                a.clear();
                q.push(NULL);
                continue;
            }
            
            a.push_back(curr->val);
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
        res.push_back(a);
        reverse(res.begin(),res.end());
        
        return res;
    }
};
