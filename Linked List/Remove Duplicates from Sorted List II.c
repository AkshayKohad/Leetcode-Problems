/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
struct ListNode*p=(struct ListNode*)malloc(sizeof(struct ListNode*));
        struct ListNode*q=(struct ListNode*)malloc(sizeof(struct ListNode*));
        struct ListNode*r=(struct ListNode*)malloc(sizeof(struct ListNode*));
    if(head==NULL)
        return NULL;
        p=head;
        int l=head->val;
        while(p!=NULL)
        {
            if(l<p->val)
                l=p->val;
            p=p->next;
        }
    p=head;
   int y=0;
    while(p!=NULL)
    {
        if(p->val<0 && y<abs(p->val))
            y=abs(p->val);
        p=p->next;
    }
        int a[l+1+y];
        for(int i=0;i<=l+y;i++)
        {
            a[i]=-1;
        }
        
        p=head;
        while(p!=NULL)
        {
            if(p->val>=0)
            a[p->val]++;
            else if(p->val<0)
                a[((-1)*(p->val))+l]++;
            p=p->next;
        }
        p=head->next;
        q=head;
        while(p!=NULL)
        {
            
            if(head->val>=0 &&a[head->val]>=1)
            {
                r=head;
                head=head->next;
                free(r);
                q=head;
                p=head->next;
            }
            else if(head->val<0 &&a[((-1)*(head->val))+l]>=1)
             {
                r=head;
                head=head->next;
                free(r);
                q=head;
                p=head->next;
            }
            else if( p->val>=0 && a[p->val]>=1)
            {
                r=p;
                q->next=p->next;
                
                p=p->next;
                // q=p;
                free(r);
            }
            else if(p->val<0 && a[((-1)*(p->val))+l]>=1)
            {
                 r=p;
                q->next=p->next;
                
                p=p->next;
                // q=p;
                free(r);
            }
            else if(p->val>=0 && a[p->val]<1)
            {
                q=p;
                p=p->next;
            } 
            
              else if(p->val<0 && a[((-1)*(p->val))+l]<1)
            {
                q=p;
                p=p->next;
            } 
         }
     if(head->val>=0 &&a[head->val]>=1)
            {
         return NULL;
               
            }
            else if(head->val<0 &&a[((-1)*(head->val))+l]>=1)
             {
                return NULL;
               
            }
    p=head;
    return head;
        
}

