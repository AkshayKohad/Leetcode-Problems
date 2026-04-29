class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

     long long sum_ascending = 0;
     long long sum_descending = 0;

     int n = nums.size();
     int peak = 0;
     for(int i=0;i<n-1;i++){
        peak = max(nums[i],peak);
        if(nums[i]<nums[i+1]){
            sum_ascending += nums[i];
        }else{
            sum_descending += nums[i];
        }
     }

     peak = max(peak,nums[n-1]);
     sum_descending += nums[n-1];
     sum_ascending += peak;

     if(sum_descending == sum_ascending)return -1;
     if(sum_descending < sum_ascending)return 0;
     return 1;

    }
};
