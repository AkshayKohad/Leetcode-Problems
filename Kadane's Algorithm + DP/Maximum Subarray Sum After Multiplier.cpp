class Solution {
public:
    long long Transform(int val,bool isPositive,int k){
        if(isPositive){
            return (long long)val*k;
        }else{
            if(val<0){
                long long res = -val;
                res = res/(long long) k;
                return -res;
             }else{
                long long res = val;
                return res/k;
             }
        }
    }
    long long result(vector<int>&nums,int k,bool isPositive){
        int n = nums.size();
        vector<long long>nt(n);
        vector<long long>ct(n);
        vector<long long>et(n);

        nt[0] = (long long)nums[0];
        ct[0] = Transform(nums[0],isPositive,k);
        et[0] = LLONG_MIN/8;

        for(int i=1;i<n;i++){
            nt[i] = max({nt[i-1] + (long long)nums[i],(long long)nums[i]});
            ct[i] = max({ct[i-1] + Transform(nums[i],isPositive,k),nt[i-1] + Transform(nums[i],isPositive,k),Transform(nums[i],isPositive,k)});
            et[i] = max({ct[i-1] + (long long)nums[i],et[i-1] + (long long)nums[i]});
        }
        long long result_max = LLONG_MIN;
        for(int i=0;i<n;i++){
            result_max = max({result_max,ct[i],et[i]});
        }
        return result_max;

    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        return max(result(nums,k,false),result(nums,k,true));
    }
};

// nt(i) -> max(nt(i-1) + nums[i], nums[i]);
// ct(i) -> max(ct(i-1) + T(nums[i]), nt(i-1) + T(nums[i]), T(nums[i]));
// et(i) -> max(ct(i-1) + nums[i], et(i-1) + nums[i]);

// return max(et(n-1),ct(n-1));
