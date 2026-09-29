class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix_sum(n);

        prefix_sum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i]; 
        }

        int res = n + 1;
        deque<int> min_deque;

        for(int i = 0; i < n; i++){

            if(prefix_sum[i] >= k){
                res = min(res, i + 1);
            }

            while(!min_deque.empty() &&
                  prefix_sum[i] - prefix_sum[min_deque.front()] >= k){

                res = min(res, i - min_deque.front()); // FIX
                min_deque.pop_front();
            }

            while(!min_deque.empty() &&
                  prefix_sum[min_deque.back()] >= prefix_sum[i]){

                min_deque.pop_back();
            }

            min_deque.push_back(i);
        }

        return res == n + 1 ? -1 : res;
    }
};
