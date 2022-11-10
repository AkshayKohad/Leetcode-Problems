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
class FindElements {
public:
    TreeNode*head;
    
    void recover(TreeNode*head)
    {
        if(head==NULL)
            return;
        
        int x = head->val;
        
        if(head->left != NULL)
        head->left->val = 2*x+1;
        
        if(head->right!=NULL)
        head->right->val = 2*x+2;
        
        recover(head->left);
        recover(head->right);
        
        
        
    }
    
    FindElements(TreeNode* root) {
        head = root;
        head->val = 0;
        recover(head);
    }
    
    bool find_recover_tree(TreeNode*head,int target)
    {
        if(head==NULL)
            return false;
        
        if(head->val==target)
            return true;
        
        return find_recover_tree(head->left,target) || find_recover_tree(head->right,target); 
    }
    
    bool find(int target) {
        
       return find_recover_tree(head,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
