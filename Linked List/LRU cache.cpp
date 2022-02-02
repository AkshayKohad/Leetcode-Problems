class LRUCache {
public:
    
    class Node{
        public:
        int key;
        int val;
        
        Node*next;
        Node*prev;
        
        Node(int key,int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    
    int capacity;
    Node*head = new Node(-1,-1);
    Node*tail = new Node(-1,-1);
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node*curr)
    {
        Node*temp = head->next;
        
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
    }
    
    
    void deleteNode(Node*curr)
    {
        Node*curr_prev = curr->prev;
        Node*curr_next = curr->next;
        
        curr_prev->next = curr_next;
        curr_next->prev = curr_prev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        Node*curr = mp[key];
        mp.erase(key);
        deleteNode(curr);
        addNode(curr);
        mp[key] = head->next;
        
        
        
        return curr->val;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            Node*curr = mp[key];
            deleteNode(curr);
            mp.erase(key);
        }
        
        if(mp.size()==capacity)
        {
            mp.erase(tail->prev->key);
            Node*temp = tail->prev;
            deleteNode(tail->prev);
            delete temp;
        }
        
       
            Node*curr = new Node(key,value);
            addNode(curr);
            mp[key] = head->next;
        
    }
};
