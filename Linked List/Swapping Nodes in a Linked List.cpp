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
    ListNode* swapNodes(ListNode* head, int k) {
        
        
        // to find kth node from begining 
        
        ListNode*begin_prev = NULL;
        ListNode*begin_cur = head;
        
        int t = k-1;
        
        while(t--)
        {
            begin_prev = begin_cur;
            begin_cur = begin_cur->next;
        }
        
        
        
        // to find kth node from end
        
        ListNode*end_fast = head;
        ListNode*end_cur = head;
        ListNode*end_prev = NULL;
        
        
        t = k-1;
        
        while(t--)
        {
            end_fast = end_fast->next;
            
        }
        
        
        while(end_fast->next!=NULL)
        {
            end_prev = end_cur;
            
            end_cur = end_cur->next;
            
            end_fast = end_fast->next;
        }
        
        
        // if size of list is n==1 then it is condition for this
        
        if(begin_prev == NULL && end_prev == NULL)
            return head;
        
        
        // if n>1 and k==1
        
        else if(begin_prev == NULL)
        {
            end_prev->next = begin_cur;
            
            end_cur->next = begin_cur->next;
            
            begin_cur->next = NULL;
            
            head = end_cur;
        }
        
        
        // if n>1 and k==n
        
        else if(end_prev == NULL)
        {
            begin_prev->next = end_cur;
            
            begin_cur->next = end_cur->next;
            
            end_cur->next = NULL;
            
            head = begin_cur;
        }
        
       //middle cases (cases without edges cases)
        
        else{
            begin_prev->next = end_cur;
            
            end_prev->next = begin_cur;
            
            ListNode*temp = begin_cur->next;
            
            begin_cur->next = end_cur->next;
            
            end_cur->next = temp;
            
        }
        
        
        return head;
        
        
    }
};
