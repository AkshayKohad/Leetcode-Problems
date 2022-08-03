class MyCalendar {
public:
    
    struct cmp{//custom comparator for set
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const{
        if(p1.second==p2.second)
            return p1.first<p2.first;
        
        return p1.second<p2.second;
        
        
    }  
};
    
    set<pair<int,int>,cmp>s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto k : s)
        {
            int s = k.first;
            int e = k.second;
            
            if(s<end && start<e) return false;
            
        }
        
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
