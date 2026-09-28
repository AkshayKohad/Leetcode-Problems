class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int>max_queue;
        deque<int>min_queue;
        int left_index = 0;
        int right_index = 0;
        int res = 0;
        while(right_index < n){
            while(max_queue.empty()==false && nums[max_queue.back()] <= nums[right_index])max_queue.pop_back();

            while(min_queue.empty()==false && nums[min_queue.back()] >= nums[right_index])min_queue.pop_back();

            max_queue.push_back(right_index);
            min_queue.push_back(right_index);
            right_index++;


            int maxi_val = nums[max_queue.front()];
            int mini_val = nums[min_queue.front()];

            while(maxi_val - mini_val > limit){
                left_index = min(max_queue.front(),min_queue.front())+1;
                if(max_queue.empty()==false && max_queue.front() < left_index) max_queue.pop_front();
                if(min_queue.empty()==false && min_queue.front() < left_index) min_queue.pop_front();
                maxi_val = nums[max_queue.front()];
                mini_val = nums[min_queue.front()];
            }
            
            res = max(res,right_index-left_index);
        }

        return res;
    }
};
