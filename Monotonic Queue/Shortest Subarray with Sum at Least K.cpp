class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>max_queue;
        int n = nums.size();

        vector<int>result;
        for(int i=0;i<n;i++){
            if(max_queue.empty()==false && max_queue.front() <= i-k)max_queue.pop_front();

            while(max_queue.empty()==false && nums[max_queue.back()] <= nums[i])max_queue.pop_back();

            max_queue.push_back(i);

            if(i-k+1 >=0){
                result.push_back(nums[max_queue.front()]);
            }
        }

        return result;
    }
};
