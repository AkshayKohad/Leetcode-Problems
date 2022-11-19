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
public:
    ListNode* mergeNodes(ListNode* head) {
        
        
        ListNode*p = head;
        ListNode*q = head->next;
        
        ListNode*head1=NULL;
        ListNode*n = NULL;
        while(q!=NULL)
        {
            
            while(q!=NULL && q->val!=0)
            {
              q = q->next;    
            }
            
            ListNode*t = p;
            
            int value = 0;
            
            while(t!=q)
            {
            
                value += t->val;
                t = t->next;
            }
           
            ListNode*node = new ListNode(value);
            
            if(head1==NULL)
            {
                head1=node;
                head1->next = NULL;
                
                n = head1;
            }
            
            else{
                n->next = node;
                n = node;
            }
            
            p = q;
            q=q->next;
        }
        
        return head1;
    }
};
