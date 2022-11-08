class Solution {
public:
    
     unordered_map<int,int>mp;
    
     int range;  
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        
        int top = n-m;
        range  = n-m;
        
        unordered_set<int>blacklist_numbers;
        
        
        for(int i=0;i<m;i++)
        {
            blacklist_numbers.insert(blacklist[i]);
        }   
        
        for(auto num : blacklist)
        {
            
            if(num<range)
            {
                while(blacklist_numbers.find(top)!=blacklist_numbers.end())
                {
                    top++;
                }
                
                mp[num] = top;
                
                top++;
            }
        }
    }
    
    int pick() {
        
        
        int val = rand() % range;
        
        if(mp.find(val)!=mp.end())
        {
           return mp[val];
        }
        
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
