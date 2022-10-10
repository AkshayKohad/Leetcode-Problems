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
    vector<int> nextLargerNodes(ListNode* head) {
      
       ListNode*r = head;
        int count = 0;
        
        while(r!=NULL)
        {
            count++;
            r=r->next;
        }
        
        
       vector<int>res(count); 
        stack<pair<int,int>>st;
        
        ListNode*p = head;
        
        int i = 0;
        
        while(p!=NULL)
        {
            while(st.empty()==false && st.top().second < p->val)
            {
                int index = st.top().first;
                
                res[index] = p->val;
                
                st.pop();
            }
            
            
            st.push({i,p->val});
                
            i++;
            p=p->next;
            
        }
        
        while(st.empty()==false)
            {
                 int index = st.top().first;
                
                res[index] = 0;
                
                st.pop();
            }
        
        return res;
    }
};
