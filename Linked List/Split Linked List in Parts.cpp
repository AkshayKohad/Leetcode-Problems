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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int count  = 0;
        
        ListNode*p = head;
        
        while(p!=NULL)
        {
            count++;
            p = p->next;
        }
        
        
        int rem = count%k;
        
        int q = count/k;
        
        vector<ListNode*>res;
        ListNode*cur = head;
        
        while(cur!=NULL)
        {
            ListNode*t = cur;
            ListNode*e = cur;
            
            int w  = q;
            while(cur!=NULL && w--)
            {
                e=cur;
                cur = cur->next;
            }
            
           
            
            if( cur!=NULL && rem>0 )
            {
                e = cur;
                
                cur = cur->next;
                
                rem--;
            }
            
             res.push_back(t);
            e = e->next = NULL;
        }
        
        
        while(k>res.size())
        {
            res.push_back(NULL);
        }
        
        return res;
    }
};
