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
class Solution {
    
    ListNode*merge(ListNode*node1,ListNode*node2)
    {
        if(node1==NULL && node2==NULL)
            return NULL;
        else if(node1==NULL)
            return node2;
        
        else if(node2==NULL)
            return node1;
        
          ListNode*root=NULL;
        ListNode*p=node1;
        ListNode*q=node2;
        ListNode*r=NULL;
        if(p->val<q->val)
        {
            root=p;
            r=root;
            p=p->next;
            
        }
        else
        {
            root=q;
            r=root;
            q=q->next;
        }
        
        while(p!=NULL && q!=NULL)
        {
            if(p->val<q->val)
            {
                r->next=p;
                r=p;
                p=p->next;
            }
            
            else{
                r->next=q;
                r=q;
                q=q->next;
            }
        }
        
        if(p!=NULL)
        {
            r->next=p;
        }
        
        if(q!=NULL)
        {
            r->next=q;
        }
        
        return root;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*root=NULL;
        for(int i=0;i<lists.size();i++)
        {
            root = merge(root,lists[i]);
        }
        
        return root;
    }
};
