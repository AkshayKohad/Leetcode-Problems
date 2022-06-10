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
    ListNode* rotateRight(ListNode* head, int k) {
     
        
        if(head==NULL)
            return head;
        int count = 0;
    ListNode*curr = head;
    while(curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    
    k = k%count;
    
    if(k==0)
        return head;
    
    curr = head;
    ListNode*prev = NULL;
    
    int res = count-k;
    while(res--)
    {
        
        prev = curr;
        curr = curr->next;
    }
    
   
    prev->next = NULL;
    ListNode*t = curr;
     while(t->next!=NULL)
     {
         t=t->next;
     }
    
    t->next = head;
    head = curr;
    
    return head;

    }
};
