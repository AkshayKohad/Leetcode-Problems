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
 #define ll long long
class Solution {
public:
    bool isLeaf(TreeNode*root){
        if(root->left == NULL && root->right == NULL)return true;
        return false;
    }
    void solve(TreeNode* root,ll &curSum,int targetSum,unordered_map<ll,int>&mp,int &result){
        if(root == NULL)return;
        if(isLeaf(root)){
            int val = root->val;
            curSum += (ll)val;
            result += mp[curSum-targetSum];
            curSum -= (ll)val;
            return;
        }

        curSum += (ll)root->val;
        result += mp[curSum-targetSum];
        mp[curSum]++;
        solve(root->left,curSum,targetSum,mp,result);
        solve(root->right,curSum,targetSum,mp,result);
        mp[curSum]--;
        curSum -= (ll)root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,int>mp;
        int result = 0;
        mp[0] = 1;
        ll curSum = 0;
        solve(root,curSum,targetSum,mp,result);
        return result;
    }
};
