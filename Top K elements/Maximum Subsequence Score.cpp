class Solution {
public:
    static bool mycmp(pair<int,int>f,pair<int,int>s){
        return f.first > s.first;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>nums;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            nums.push_back({nums2[i],nums1[i]});
        }

        sort(nums.begin(),nums.end(),mycmp);

        priority_queue<int,vector<int>,greater<int>>pq;
        long long cur_sum = 0;
        long long res_cost = 0;
        for(int i=0;i<n;i++){
         cur_sum += nums[i].second;
         pq.push(nums[i].second);
         if(pq.size() > k){
            cur_sum -= pq.top();
            pq.pop();
         }  
         if(pq.size() == k){
            res_cost = max(res_cost,cur_sum*(long long)nums[i].first);
         }

        }

        return res_cost;
    }
};
