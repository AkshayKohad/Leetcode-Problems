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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*slowest=NULL;
        
        int c = 1;
    
    while(c!=n)
    {
        fast = fast->next;
        c++;
    }
        
    while(fast->next!=NULL)
    {
        slowest=slow;
        slow=slow->next;
        fast=fast->next;
    }
        
        
        if(slowest==NULL)
        {
          ListNode*temp = slow;
            slow=slow->next;
            head=slow;
            delete temp;
            
        }
        
        else{
            ListNode*temp = slow;
            slowest->next = slow->next;
            delete temp;
        }
        return head;
        
    }
    
    
};
