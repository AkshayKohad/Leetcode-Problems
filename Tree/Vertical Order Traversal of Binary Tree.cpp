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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        map<int,map<int,multiset<int>>>mp;
        
        
        
        while(q.empty()==false)
        {
           pair<TreeNode*,pair<int,int>>curr = q.front();
            
            q.pop();
            
            TreeNode*nd = curr.first;
            
            int x = curr.second.first;
            int y = curr.second.second;
            
            mp[x][y].insert(nd->val);
            
            if(nd->left!=NULL)
            {
                q.push({nd->left,{x-1,y+1}});
            }
            
            if(nd->right!=NULL)
            {
                q.push({nd->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>>ans;
        
        for(auto x : mp)
        {
            vector<int>t;
            for(auto y : x.second)
            {
                for(auto u : y.second)
                {
                    t.push_back(u);
                }
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};
