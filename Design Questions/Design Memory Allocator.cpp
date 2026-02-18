class Allocator {
public:
    vector<int>memory;
    int n;
    Allocator(int n) {
        memory.assign(n,-1);
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        int l=0;
        int start = -1;
        while(l<n){
            if(memory[l]!=-1){
                l++;
                continue;
            }
            int cnt = 0;
            int r = l;

            while(r<n && memory[r]==-1){
                r++;
                cnt++;
            }

            if(cnt>=size){
                start = l;
                break;
            }
            l = r;
        }
        if(start==-1)return -1;
        int st = start;
        while(size--){
            memory[st] = mID;
            st++;
        }
        return start;
    }
    
    int freeMemory(int mID) {
        int res_cnt = 0;
        for(int i=0;i<n;i++){
            if(memory[i] == mID){
                res_cnt++;
                memory[i] = -1;
            }
        }
        return res_cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
