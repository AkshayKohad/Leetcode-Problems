/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
int c=0;
    struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode*));
     struct ListNode*q=(struct ListNode*)malloc(sizeof(struct ListNode*));
    struct ListNode*r=(struct ListNode*)malloc(sizeof(struct ListNode*));
    p=head;
    q=NULL;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    if(c==0)
        return head;
    c=c-n;
    if(c==0)
    {
        q=head;
        head=head->next;
        free(q);
    }
    else if(n==0)
    {
        if(c==1)
            return head;
        p=head;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
         r=p;
        q->next=p->next;
        free(r);
    }
    else
    {
        p=head;
        
        while(c--)
        {
            q=p;
          p=p->next;  
        }
        r=p;
        q->next=p->next;
        free(r);
    }
    return head;
}

