class FrontMiddleBackQueue {
public:
    deque<int> x1, x2;
    
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        x1.push_front(val);
        if(x1.size() > x2.size()) {
            x2.push_front(x1.back());
            x1.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        if(x2.size() == x1.size()) {x2.push_front(val);}
        else {
            x1.push_back(val);
        }
        
    }
    
    void pushBack(int val) {
        x2.push_back(val);
        if(x2.size() - x1.size() > 1) {
            x1.push_back(x2.front());
            x2.pop_front();
        }
    }
    
    int popFront() {
        int ans = -1;
        if(x1.size() > 0) {
            ans = x1.front();
            x1.pop_front();
        }
        else {
            if(x2.size() > 0) {
                ans = x2.front();
                x2.pop_front();
            }
        }
        if(x2.size() - x1.size() > 1) {
            x1.push_back(x2.front());
            x2.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        int ans = -1;
        if(x2.size() > x1.size()) {ans = x2.front(); x2.pop_front();}
        else {
            if(x1.size() > 0) {
                ans = x1.back();
                x1.pop_back();
            }
        }
        return ans;
    }
    
    int popBack() {
        int ans = -1;
        if(x2.size() > 0) { 
            ans = x2.back();
            x2.pop_back();
        }
        if(x1.size() > x2.size()) {
            x2.push_front(x1.back());
            x1.pop_back();
        }
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
