class FreqStack {
public:
 
    unordered_map<int,int>ele;  // element to occurence
    unordered_map<int,stack<int>>freq; // frequency to stack which stores recent element
    
    int max_freq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        ele[val]++;
        int frequency = ele[val];
        
        max_freq = max(max_freq,frequency);
        
        freq[frequency].push(val);
    }
    
    int pop() {
        
        int res = freq[max_freq].top();
        
        freq[max_freq].pop();
        
        
        
        if(freq[max_freq].size()==0)
        {
            freq.erase(max_freq);
            max_freq--;
        }
        
        
        int frequency = ele[res];
        
        if(frequency>1)
        {
         
            ele[res]--;
        }
        
        else{
            ele.erase(res);
        }
        
        
        return res;
    }
};

