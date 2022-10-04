// Using Inorder array

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>&inorder,int l,int r)
    {
        if(l>r)
            return NULL;
        
        
        int mid = (l+r)/2;
        
        TreeNode*left = solve(inorder,l,mid-1);
        
        TreeNode*right = solve(inorder,mid+1,r);
        
        TreeNode*root = new TreeNode(inorder[mid]);
        
        root->left = left;
        
        root->right = right;
        
        
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int>inorder;
        
        ListNode*t = head;
        
        while(t!=NULL)
        {
            inorder.push_back(t->val);
            t = t->next;
        }
        
        int n = inorder.size();
        
        return solve(inorder,0,n-1);
        
        
    }
};




// Using Linked List


ListNode* middle(ListNode* start,ListNode* end)
{
    if(start==NULL)
    {
        return NULL;
    }
    
    ListNode* slow = start;
    ListNode* fast = start->next;
    
    while(fast!=end && fast->next!=end)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

TreeNode* solve(ListNode* start,ListNode* end)
{
    if(start==end)
    {
        return NULL;
    }
    
    ListNode* mid = middle(start,end);
    
    TreeNode* root = new TreeNode(mid->val);
    
    root->left = solve(start,mid);
    root->right = solve(mid->next,end);
    
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    
    if(head==NULL)
    {
        return NULL;
    }
    
    TreeNode* ans = solve(head,NULL);
    
    return ans;
    
}
