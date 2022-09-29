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
    
    TreeNode*solve(int &i,vector<pair<int,int>>&a,int &m,int level,TreeNode*root)
    {
       if(i==m)
       {
           return root;
       }
        
        if(level == a[i].first)
        {
            root = new TreeNode(a[i].second);
            i++;
            root->left = solve(i,a,m,level+1,root->left);
            
            root->right = solve(i,a,m,level+1,root->right);
        }
        
        else if(level>a[i].first)
            return root;
        
        else{
          
            root->left = solve(i,a,m,level+1,root->left);
            
            root->right = solve(i,a,m,level+1,root->right);
        }
        
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        
        int i=0;
        int n = traversal.length();
        
        
        vector<pair<int,int>>a;
        unordered_map<int,int>mp;
        while(i<n)
        {
            int countdash = 0;
            while(i<n && traversal[i]=='-')
            {
                countdash++;
                i++;
            }
            
            string s;
            while(i<n && traversal[i]!='-')
            {
                s.push_back(traversal[i]);
                i++;
            }
          
            stringstream geek(s);
            int num;
            geek>>num;
            
           
            
            a.push_back({countdash,num});
            
            
        }
        
        TreeNode*root = new TreeNode(a[0].second);
        int m = a.size();
         i = 1;
        solve(i,a,m,0,root);
        return root;
    }
};
