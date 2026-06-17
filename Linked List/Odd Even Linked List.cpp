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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)return head;
    
    ListNode*odd = head;
    ListNode*even_head = head->next;
    ListNode*even = head->next;
    int chance = 0;
    while(odd!=NULL && even!=NULL){
        if(chance%2==0){
            ListNode*odd_next = even->next;
            odd->next = odd_next;
            even->next = NULL;
            if(odd_next == NULL)break;
            odd = odd_next;
        }else{
            ListNode*even_next = odd->next;
            even->next = even_next;
            odd->next = NULL;
            if(even_next == NULL)break;
            even = even_next;
        }
        chance++;
    }
    odd->next = even_head;
    return head;
    }
};
