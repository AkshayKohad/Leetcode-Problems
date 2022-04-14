class CustomStack {
public:
    int *st;
    int size;
    int curr;
    CustomStack(int maxSize) {
        curr = -1;
        size = maxSize;
        st = new int[maxSize];
    }
    
    void push(int x) {
        if(curr<size-1)
        {
            curr++;
            st[curr] = x;
            
        }
            
    }
    
    int pop() {
        if(curr==-1)
            return -1;
        
        int x = st[curr];
        curr--;
        return x;
    }
    
    void increment(int k, int val) {
        
        if(curr<=k-1)
        {
            for(int i=0;i<=curr;i++)
                st[i] += val;
        }
        
        else{
            for(int i=0;i<k;i++)
                st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
