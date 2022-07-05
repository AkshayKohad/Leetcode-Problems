class BSTIterator {
public:
    stack<TreeNode*>st;
    
    BSTIterator(TreeNode* root) {
        pushL(root);
    }
    
    int next() {
        int x = st.top()->val;
        TreeNode*root = st.top();
        st.pop();
        pushL(root->right);
        
        return x;
    }
    
    bool hasNext() {
        return st.empty()==false;
    }
    
    private:
    
    void pushL(TreeNode*root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};

