class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>nums;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            nums.push_back({nums1[i],nums2[i],i});
        }
        sort(nums.begin(),nums.end());
        int i=0;
        long long cur_sum = 0;
        vector<long long>result(n,-1);
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        while(i<n){

            while(pq.size()>k){
                cur_sum -= pq.top();
                pq.pop();
            }

            int j=i;
            while(j<n && nums[i][0] == nums[j][0]){
                result[nums[j][2]] = cur_sum;
                j++;
            }

            while(i<j){
                pq.push(nums[i][1]);
                cur_sum += nums[i][1];
                i++;
            }

        }
        return result;
    }
};
