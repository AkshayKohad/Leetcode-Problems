/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode*));
struct ListNode*q=(struct ListNode*)malloc(sizeof(struct ListNode*));
struct ListNode*r=(struct ListNode*)malloc(sizeof(struct ListNode*));
struct ListNode*t=(struct ListNode*)malloc(sizeof(struct ListNode*));
struct ListNode*v=(struct ListNode*)malloc(sizeof(struct ListNode*));
    if(head==NULL || head->next==NULL)
        return head;
    p=head;
    int l=m-1;
    int k=n-1;
    t=head;
    while(l--)
    {
        t=p;
        p=p->next;
    }
    p=head;
    while(k--)
    {
        p=p->next;
        
    }
    v=p->next;
    p->next=NULL;
    
    // struct ListNode*head1=(struct ListNode*)malloc(sizeof(struct ListNode*));
    // head1=p;
    if(m==1)
        p=head;
    else
    p=t->next;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
     r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    // head1=q;
   if(m==1)
   {
       head->next=v;
       head=q;
   }
    else if(m>1)
    {
    t->next=q;
    
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=v;
    }
    return head;
}

