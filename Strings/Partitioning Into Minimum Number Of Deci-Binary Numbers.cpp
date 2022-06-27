class Solution {
public:
    int minPartitions(string n) {
        
        
        int res = 0;
        
        for(int i=0;i<n.length();i++)
        {
            int val = n[i] - '0';
            
            res = max(res,val);
        }
            
        return res;
        
        
    }
};
