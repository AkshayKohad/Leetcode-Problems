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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*head2 = list2;
        
        ListNode*t = list2;
        
        while(t->next!=NULL)
        {
            t=t->next;
        }
        
        ListNode*tail2 = t;
        
        ListNode*r = NULL;
        ListNode*p = list1;
        
        ListNode*start;
        int count = 0;
        while(p!=NULL && count!=a)
        {
            r = p;
            p = p->next;
            
            count++;
            
           
            
            
        }
        r->next = head2;
                start = p;
        
        while(p!=NULL && count!=b)
        {
            r = p;
            p=p->next;
            
            count++;
        }
        
         ListNode*temp = p->next;
                
                tail2->next = temp;
                
                p->next = NULL;
        
        ListNode*prev;
        while(start!=NULL)
        {
            prev = start;
            start = start->next;
            delete prev;
        }
        
        return list1;
    }
};
