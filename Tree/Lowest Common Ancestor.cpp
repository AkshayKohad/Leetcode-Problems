/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// using concept of in time and out time in each nodes
class Solution {
public:
    
    
    void solve(TreeNode*root,int n1,int n2,unordered_map<int,int>&inside,unordered_map<int,int>&outside,int&res)
    {
        
        if(root==NULL)
        return;
        
        if(inside[root->val]<= inside[n1] && inside[root->val] <= inside[n2] && outside[root->val]>= outside[n1] && outside[root->val]>= outside[n2])
        {
            res = root->val;
            
            solve(root->left,n1,n2,inside,outside,res);
            
            solve(root->right,n1,n2,inside,outside,res);
            
            
            
            
        }
        
        else{
            return;
        }
        
    }
    
    void traverse(TreeNode*root,unordered_map<int,int>&inside,unordered_map<int,int>&outside,int&timer)
    {
        if(root==NULL)
        return;
        
        inside[root->val] = timer++;
        
        traverse(root->left,inside,outside,timer);
        
        traverse(root->right,inside,outside,timer);
        
        outside[root->val] = timer++;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         unordered_map<int,int>inside;
        unordered_map<int,int>outside;
        
        int timer = 0;
        
        traverse(root,inside,outside,timer);
        
        int res;
        
        // if(inside.find(n1)==inside.end() || inside.find(n2)==inside.end())
        // return root;
        int n1 = p->val;
        int n2 = q->val;
        solve(root,n1,n2,inside,outside,res);
        
         TreeNode *ans = new TreeNode(res);
        return ans;
    }
};
