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
    int solve(TreeNode*root,int &count_camera){
        if(root==NULL)return 2;

        int left = solve(root->left,count_camera);
        int right = solve(root->right,count_camera);

        if(left==0 || right==0){
            count_camera++;
            return 1;
        }else if(left==1 || right==1){
            return 2;
        }

        return 0;
        
    }
    int minCameraCover(TreeNode* root) {
        int count_camera = 0;

        if(solve(root,count_camera)==0)count_camera++;

        return count_camera;
    }
};
