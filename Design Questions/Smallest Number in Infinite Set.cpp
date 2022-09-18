class SmallestInfiniteSet {
public:
    
    set<int>removed_record;
    int mini = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int val = mini;
        
        removed_record.insert(mini);
        
        while(removed_record.find(mini)!=removed_record.end())
            mini += 1;
        
        return val;
    }
    
    void addBack(int num) {
        mini = min(mini,num);
        
        removed_record.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
