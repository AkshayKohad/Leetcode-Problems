class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int>res;
        
        int q = queries.size();
        
        for(int i=0;i<q;i++)
        {
            int k = queries[i][0];
            int trim = queries[i][1];
            
            priority_queue<pair<string,int>>pq;
            
            for(int i=0;i<nums.size();i++)
            {
                int size = nums[i].length();
                
                string t = nums[i].substr(size-trim);
                
                
                pq.push({t,i});
                
                if(pq.size()>k) pq.pop();
            }
            
            res.push_back(pq.top().second);
            
        }
        
        
        return res;
    }
};
