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
    
    void traverse(TreeNode*root,vector<int>&a)
    {
        if(root==NULL)
            return;
        
        traverse(root->left,a);
        
        a.push_back(root->val);
        
        traverse(root->right,a);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int>arr1;
        vector<int>arr2;
        
        traverse(root1,arr1);
        traverse(root2,arr2);
        
        
        int n = arr1.size();
        int m = arr2.size();
        
        
        int i=0;
        int j=0;
        
        vector<int>res;
        
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                res.push_back(arr1[i]);
                i++;
            }
            
            else{
                res.push_back(arr2[j]);
                j++;
            }
        }
        
        
        while(i<n)
        {
            res.push_back(arr1[i]);
            i++;
        }
        
        
        while(j<m)
        {
            res.push_back(arr2[j]);
            j++;
        }
        
        return res;
    }
};
