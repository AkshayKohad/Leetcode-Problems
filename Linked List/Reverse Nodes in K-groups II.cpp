//https://www.codingninjas.com/codestudio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

void reverse(Node*start,Node*end)
{
    Node*p = start;
    Node*q = start;
    Node*r = NULL;
    
    while(q!=end)
    {
        q = q->next;
        p ->next = r;
        r = p;
        p=q;
    }
   
    p->next = r;
    
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    int flag = 0;
        Node *slow = head;
        Node *fast = head;
        Node *slowest = NULL;
    int i = 0;
        while(slow!=NULL && i<n)
        {
            
            int c = 1;
            int size = b[i];
            i++;
            
            if(size==0)
                continue;
            while(fast->next!=NULL && c!=size)
            {
                c++;
                fast=fast->next;
            }
            
            if(c!=size)
            {
                flag=1;
                break;
            }
            Node *next_start = fast->next;
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
        
    
    
    if(flag == 1)
    {
        if(slow==NULL)
            return head;
        
        Node*p = slow;
        Node*r = NULL;
        while(p!=NULL)
        {
            r=p;
            p=p->next;
        }
        
        reverse(slow,r);
        
        if(slowest == NULL)
        {
            head = r;
            
        }
        else{
            slowest->next = r;
        }
    }
    return head;
    
}
