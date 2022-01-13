class StockSpanner {
public:
    vector<int>a;
    vector<int>b;
    stack<int>s;
    StockSpanner() {
        
    }
    
    int next(int price) {
       a.push_back(price);
       
        //stack<int>s;
       // a.push_back(price);
        
            int val=0;
            
            while(s.empty()==false && a[s.top()]<=price)
            {
                val = val + b[s.top()];
                s.pop();
            }
            
            s.push(a.size()-1);
            b.push_back(val+1);  
        
        return val+1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
