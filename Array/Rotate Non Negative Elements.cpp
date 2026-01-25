class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>positive;

        for(int i=0;i<n;i++){
            if(nums[i]>=0)positive.push_back(nums[i]);
        }

        int m = positive.size();

        if(m==0)return nums;

        k = k%m;

        vector<int>update_positive(m);
        for(int i=0;i<m;i++){
            int new_i = (i-k+m)%m;
            update_positive[new_i] = positive[i];
        }

        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i] = update_positive[j];
                j++;
            }
        }

        return nums;
    }
};
