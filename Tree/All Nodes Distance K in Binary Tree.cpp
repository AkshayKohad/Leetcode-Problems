/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    map<TreeNode*,TreeNode*>parent;
    
    unordered_set<int>visited;
    void traverse(TreeNode*root)
    {
        if(root==NULL)
            return;
        
        
        int par = root->val;
        
        if(root->left)
        {
            int x = root->left->val;
            parent[root->left] = root;    
            
            
            traverse(root->left);
        }
        
        if(root->right)
        {
            int x = root->right->val;
            parent[root->right] = root;
            
            
            traverse(root->right);
        }
        
        
    }
    
    
    void solve(TreeNode*target,int k,vector<int>&res)
    {
        if(target==NULL)
            return;
        
        if(k==0)
        {
            res.push_back(target->val);
            return;
        }
        
        
        if(parent.find(target)!=parent.end())
        {
            int x = parent[target]->val;
            
            if(visited.find(x)==visited.end())
            {
               visited.insert(x); 
           solve(parent[target],k-1,res);
                
            }
        }
        
        if(target->left)
        {
            int x = target->left->val;
            
            if(visited.find(x)==visited.end())
            {
                visited.insert(x);
                solve(target->left,k-1,res);
            }
        }
        
        
        if(target->right)
        {
             int x = target->right->val;
            
            if(visited.find(x)==visited.end())
            {
                visited.insert(x);
                solve(target->right,k-1,res);
            }
        }
            
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     
        
        traverse(root);
        
    vector<int>res;
        
        visited.insert(target->val);
        solve(target,k,res);
    
        
        return res;
    }
};
