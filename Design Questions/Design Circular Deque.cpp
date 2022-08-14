class MyCircularDeque {
public:
    
    class Node{
        public:
        
        int val;
        Node*next;
        Node*prev;
        
        
        Node(int val)
        {
            this->val = val;
            next = NULL;
            prev = NULL;
        }
        
    };
    
    
    int max_capacity;
    int curr_capacity;
    
    Node *head = new Node(-1);
    Node *tail = new Node(-1);
    
    MyCircularDeque(int k) {
        
    max_capacity = k;
    curr_capacity = 0;
        
        head->next = tail;
        tail->prev = head;
    }
    
    bool insertFront(int value) {
        if(curr_capacity==max_capacity)
        {
            return false;
        }
        
        curr_capacity++;
        
        Node* make_node = new Node(value);
        
        Node*t = head->next;
        
        head->next = make_node;
        make_node->prev = head;
        
        make_node->next = t;
        t->prev = make_node;
        
        return true;
    }
    
    bool insertLast(int value) {
        if(curr_capacity==max_capacity)
            return false;
        
        
        curr_capacity++;
        
        Node* make_node = new Node(value);
        
        Node*t = tail->prev;
        
        tail->prev = make_node;
        make_node->next = tail;
        
        make_node->prev = t;
        t->next = make_node;
       
        return true;
    }
    
    bool deleteFront() {
        
        if(curr_capacity==0)
        {
            return false;
        }
        
        curr_capacity--;
        Node*t = head->next;
        
        Node*p = t->next;
        
        head->next = p;
        
        p->prev = head;
        
        delete t;
        
        return true;
    }
    
    bool deleteLast() {
        
        if(curr_capacity==0)
        {
            return false;
        }
        
        curr_capacity--;
        
        Node*t = tail->prev;
        
        Node*p = t->prev;
        
        tail->prev = p;
        
        p->next = tail;
        
        delete t;
        
        return true;
    }
    
    int getFront() {
        if(curr_capacity==0)
            return -1;
        
        return head->next->val;
    }
    
    int getRear() {
        
        if(curr_capacity==0)
            return -1;
        
        return tail->prev->val;
    }
    
    bool isEmpty() {
        if(curr_capacity==0)
            return true;
        
        return false;
    }
    
    bool isFull() {
        if(curr_capacity==max_capacity)
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
