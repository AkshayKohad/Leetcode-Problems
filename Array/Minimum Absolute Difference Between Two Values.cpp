class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int>ones_index;
        vector<int>twos_index;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ones_index.push_back(i);
            }else if(nums[i]==2){
                twos_index.push_back(i);
            }
        }

        if(ones_index.size()==0 || twos_index.size()==0)return -1;

        int i=0;
        int j=0;
        int res = n;
        while(i<ones_index.size() && j<twos_index.size()){
            res = min(res,abs(ones_index[i]-twos_index[j]));

            if(ones_index[i] < twos_index[j])i++;
            else j++;
        }

        return res;
    }
};
