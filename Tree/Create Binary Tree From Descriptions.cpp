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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        TreeNode*root;

        int par = descriptions[0][0];
        int child = descriptions[0][1];
        int isLeft = descriptions[0][2];

        unordered_map<int,TreeNode*>mp;
        unordered_set<TreeNode*>node_with_parent;
        TreeNode*par_nd = new TreeNode(par);
        TreeNode*nd = new TreeNode(child);

        mp[par] = par_nd;
        mp[child] = nd;

        node_with_parent.insert(nd);
        
        if(isLeft == 0 )
        {
            par_nd->right = nd;
        } 

        else{
            par_nd->left = nd;
        }

        for(int i=1;i<descriptions.size();i++)
        {
            par = descriptions[i][0];
            child = descriptions[i][1];
            isLeft = descriptions[i][2];

            TreeNode*par_node;
            TreeNode*node;

            if(mp.find(par)!=mp.end())
            {
                par_node = mp[par];
            }

            else{
                par_node = new TreeNode(par);
                mp[par] = par_node;
            }

            if(mp.find(child)!=mp.end())
            {
                node = mp[child];
            }

            else{
                node = new TreeNode(child);
                mp[child] = node;
            }

            if(isLeft==0)
            {
               par_node->right = node;
            }

            else{
             par_node->left = node;
            }
         
         node_with_parent.insert(node);

        }


      for(auto k:mp)
      {

          if(node_with_parent.find(k.second)==node_with_parent.end())
          {
           root = k.second;  
           break;
          }
      }
        return root;
    }
};
