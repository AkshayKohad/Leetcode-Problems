class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        
        priority_queue<pair<int,int>>pq;
        
        for(auto x : mp)
        {
           // cout<<x.first<<" "<<x.second<<endl;
          pq.push(make_pair(x.second,x.first));   
        }
        
        
        vector<int>res;
        
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
