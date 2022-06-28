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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
        if(root==NULL)
            return {};
        
        
        bool reverse = false;
        
        queue<TreeNode*>q;
        stack<int>s;
        
        vector<vector<int>>res;
        
        
        
        q.push(root);
        while(q.empty()==false)
        {
          int count = q.size();
            vector<int>a;
            for(int i=0;i<count;i++)
            {
                TreeNode*curr = q.front();
                q.pop();
                
                if(reverse)
                    s.push(curr->val);
                
                else{
                    a.push_back(curr->val);
                }
                
                if(curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            
            if(reverse)
            {
                while(s.empty()==false)
                {
                     a.push_back(s.top());
                    s.pop();
                }
            }
            
            reverse = !reverse;
            res.push_back(a);
        }
        
        
        return res;
    }
};
