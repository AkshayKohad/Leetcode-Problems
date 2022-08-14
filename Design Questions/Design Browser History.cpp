
Method - 1

//We know it is easier to move in both i.e. forward as well as backward direction in a doubly linked list. Hence we'll use it.

//In the below mentioned code curr* is representing the current tab/page and head* is representing the homepage. next* and prev* are used to point next and previous pages corresponding to every page.
//size variable is used to take account of current size of doubly-linked list.


public:
    int size=0;
    class ListNode{
        public:
        string val;
        ListNode* next;
        ListNode* prev;
        
        ListNode(string data)
        {
            val=data;
            next=NULL;
            prev=NULL;
        }
    };
     ListNode* head ;
    ListNode* curr ;
    BrowserHistory(string homepage) {
         head = new ListNode(homepage);
         curr = head;
        size++;
    }
    
    void visit(string url) {
        ListNode* node = new ListNode(url);
        curr->next = node;
        node->prev = curr;
        curr=curr->next;
        size++;
    }
    
    string back(int steps) {
        while(curr->prev && steps)
        {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
       while(curr->next && steps)
        {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};



// Method-2


class BrowserHistory {
public:
    stack<string>backward;
    stack<string>nextward;
    
    string curr;
    
    BrowserHistory(string homepage) {
     curr = homepage;   
    }
    
    void visit(string url) {
        
        while(nextward.empty()==false)  
        nextward.pop();
        
        backward.push(curr);
        curr = url;
    }
    
    string back(int steps) {
        
        string t;
        
        while(backward.empty()==false && steps!=0)
        {
            nextward.push(curr);
            
            curr = backward.top();
            
            backward.pop();
            steps--;
            
            
        }
        
        return curr;
    }
    
    string forward(int steps) {
        
        string t;
        
        while(nextward.empty()==false && steps!=0)
        {
            backward.push(curr);
            
            curr = nextward.top();
            
            nextward.pop();
            steps--;
            
            
        }
        
        return curr;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
