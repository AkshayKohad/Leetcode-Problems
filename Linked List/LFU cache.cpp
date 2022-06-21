class LFUCache {
public:
    
    
    class Node{
        public: 
        
        int key;
        int freq;
        int val;
        Node* next;
        Node* prev;
        
        Node(int k,int value)
        {
            key = k;
            val = value;
            freq = 1;
            
        }
    };
    
    int capacity;
    
    //key-Node pair
    unordered_map<int,Node*>m;
    
    //freq-Node pair
    unordered_map<int,Node*>n;
    
        
    
    LFUCache(int c) {
        capacity = c;
    }
    
    int get(int key) {
        
        if(m.find(key)==m.end())
        {
            return -1;
        }
        
        int res = m[key]->val;
        
        //cout<<res<<endl;
        
            Node* t = m[key];
            
            int f = t->freq;
            
           // Node*head = n[f];
            
            
                Node*p = t->prev;
                Node*ne = t->next;
                p->next = ne;
                ne->prev = p;
            
            
            t->freq = t->freq + 1;
            
            if(n.find(t->freq)==n.end())
            {
                Node*head = new Node(-1,-1);
                Node*tail = new Node(-1,-1);
                
                head->prev = tail;
                tail->next = head;
                
                head->next = t;
                t->prev = head;
                t->next = tail;
                tail->prev = t;
                
                n[t->freq] = head;
            }
            
            else{
                Node*head = n[t->freq];
                
                Node*r = head->next;
                head->next = t;
                t->next = r;
                r->prev = t;
                t->prev = head;
            }
        
        
        return res;
        
    }
    
    void put(int key, int value) {
        
        if(capacity==0)
            return;
        
        if(m.find(key)!=m.end())
        {
            Node*h = m[key];
            
            h->val = value;
            
            int f = h->freq;
            
            Node*start = n[f];
            
            Node*p = h->prev;
            Node*ne = h->next;
            p->next = ne;
            ne->prev = p;
            
            h->freq = h->freq+1;
            if(n.find(h->freq)==n.end())
            {
                Node*head = new Node(-1,-1);
                Node*tail = new Node(-1,-1);
                
                head->prev = tail;
                tail->next = head;
                
                head->next = h;
                h->prev = head;
                h->next = tail;
                tail->prev = h;
                
                n[h->freq] = head;
            }
            
            else{
                Node*head = n[h->freq];
                
                Node*r = head->next;
                head->next = h;
                h->next = r;
                r->prev = h;
                h->prev = head;
            }
            
        }
        else{
            
        if(m.size()==capacity)
        {
            int w = 1;
           
            while(1)
            {
                if(n.find(w)!=n.end())
                {
                    Node*h = n[w];
                    if(h->next->next==h)
                    {
                        
                    }
                    
                    
                
                    else{
                        Node*slow = n[w];
                        
                        
                        Node*tail = slow->prev;
                        Node*remove_node = tail->prev;
                        
                        Node*p = remove_node->prev;
                        Node*ne = remove_node->next;
                        
                        p->next = ne;
                        ne->prev = p;
                        
                        m.erase(remove_node->key);
                    
                        break;
                    }
                    
                   
                }
                 w++;
            }
        }
            
            
            Node*t = new Node(key,value);
            
              if(n.find(t->freq)==n.end())
            {
                Node*head = new Node(-1,-1);
                Node*tail = new Node(-1,-1);
                
                head->prev = tail;
                tail->next = head;
                
                head->next = t;
                t->prev = head;
                t->next = tail;
                tail->prev = t;
                
                n[t->freq] = head;
            }
            
            else{
                Node*head = n[t->freq];
                
                Node*r = head->next;
                head->next = t;
                t->next = r;
                r->prev = t;
                t->prev = head;
            }

            m[key] = t;
          
            
        }     
    }
};
