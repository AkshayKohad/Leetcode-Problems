class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int>max_pq;
        priority_queue<int,vector<int>,greater<int>>min_pq;

        for(auto num : nums){
            max_pq.push(num);
            min_pq.push(num);
        }

        int result = 0;
        while(k--){
            result += max_pq.top() - min_pq.top();
            max_pq.pop();
            min_pq.pop();
        }

        return result;
    }
};
