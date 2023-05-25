class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int res_xor = 0;
        
        for(int i=0;i<derived.size();i++)
        {
            res_xor = res_xor ^ derived[i]; 
        }
        
        if(res_xor==0)
            return true;
        
        return false;
    }
};
