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
    void reverse(ListNode*start,ListNode*end)
    {
        ListNode*p = start;
        ListNode*q = start;
        ListNode*r = NULL;
        
        while(q!=end)
        {
            q=q->next;
            p->next = r;
            r=p;
            p=q;
        }
        
        p->next = r;
        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slowest = NULL;
        while(slow!=NULL)
        {
            
            int c = 1;
            while(fast->next!=NULL && c!=k)
            {
                c++;
                fast=fast->next;
            }
            
            if(c!=k)
                break;
            
            ListNode *next_start = fast->next;
            reverse(slow,fast);
            
            if(slowest==NULL)
            {
                head = fast;
                
                slow->next = next_start;
                slowest = slow;
                slow=slow->next;
                fast = slow;
            }
            
            else{
                slowest->next = fast;
                slow->next = next_start;
                slowest = slow;
                slow=slow->next;
                fast = slow;
            }
        }
        
        return head;
    }
};
