class Solution {
public:
    
    TreeNode*solve(vector<int>inorder,vector<int>postorder,int instart,int inend,int poststart,int postend,map<int,int>mp)
    {
        if(instart>inend || poststart>postend)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postend]);
        
        int ele = mp[root->val];
        int nelem = ele - instart;
        
        root->left = solve(inorder,postorder,instart,ele-1,poststart,poststart+nelem-1,mp);
        
        root->right = solve(inorder,postorder,ele+1,inend,poststart+nelem,postend-1,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        
        map<int,int>mp;
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
            
        }
        
        int instart = 0;
        int inend = inorder.size();
        
        int poststart = 0;
        int postend = postorder.size()-1;
        
        return solve(inorder,postorder,instart,inend,poststart,postend,mp);
        
        
    }
};
