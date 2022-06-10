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

Node *firstNode(Node *head)
{
	//    Write your code here.
    
    Node*slow = head;
    Node*fast = head;
    
    int flag=0;
    while(fast!=NULL)
    {
        slow = slow->next;
        
        fast = fast->next;
        if(fast==NULL)
        {
            return NULL;
            
        }
        
        fast = fast->next;
        
        if(slow==fast)
        {
            break;
        }
    }
    
    if(fast==NULL)
        return NULL;
    
    Node*entry = head;
    
    while(entry!=slow)
    {
        entry = entry->next;
        slow = slow->next;
    }
    
    return slow;
}
