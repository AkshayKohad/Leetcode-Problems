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

    int maximum_in_range(int i,int j,vector<int>&nums)
    {
        int res = INT_MIN;

        for(int k = i;k<=j;k++)
        {
            res = max(res,nums[k]);
        }

        return res;
    }

    TreeNode* solve(int i,int j,vector<int>&nums,unordered_map<int,int>&mp)
    {
        if(i>j) return NULL;
         
        int value = maximum_in_range(i,j,nums);

        int index = mp[value];

        TreeNode*node = new TreeNode(value);

        node->left = solve(i,index-1,nums,mp);

        node->right = solve(index+1,j,nums,mp);

        return node; 
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         int n = nums.size();
         
         int i = 0;
         int j = n-1;

         unordered_map<int,int>mp;
         for(int k=0;k<n;k++)
         {
             mp[nums[k]] = k;
         } 

         return solve(i,j,nums,mp);
    }
};
