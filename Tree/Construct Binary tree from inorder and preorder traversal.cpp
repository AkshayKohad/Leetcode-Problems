class Solution {
public:
    
    
    TreeNode*solve(vector<int>&preorder,vector<int>&inorder,int prestart,int preend,int instart,int inend,unordered_map<int,int>mp)
    {
         if(prestart>preend || instart>inend)
             return NULL;
        
        TreeNode*root = new TreeNode(preorder[prestart]);
        
        int ele = mp[root->val];
        
        int nelem = ele - instart;
        
        root->left = solve(preorder,inorder,prestart+1,prestart+nelem,instart,ele-1,mp);
        
        root->right = solve(preorder,inorder,prestart+nelem+1,preend,ele+1,inend,mp);
        
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        
        
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]] = i;
        }
        
        int prestart = 0;
        int preend = n-1;
        
        int instart = 0;
        int inend = n-1;
        
        
        return solve(preorder,inorder,prestart,preend,instart,inend,mp);
    }
};
