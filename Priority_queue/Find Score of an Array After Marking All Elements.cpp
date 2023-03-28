class Solution {
public:
    long long findScore(vector<int>& nums) {
     
        int n = nums.size();
        set<pair<int,int>>s;
        
        for(int i=0;i<n;i++)
        {
            s.insert({nums[i],i});
        }
        
        int val = nums.size();
        
        long long score = 0;
        while(s.size()>0)
        {
            pair<int,int>cur = *(s.begin());
            
            int value = cur.first;
            int index = cur.second;
            
            s.erase({value,index});
            
            score += value;
            
            if(index-1>=0)
            {
             s.erase({nums[index-1],index-1});   
            }
            
            if(index+1<n)
            {
                s.erase({nums[index+1],index+1});
            }
        }
        
        return score;
    }
};
