class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>num_st;
        for(int i=0;i<n;i++){
            num_st.insert(nums[i]);
        }
        unordered_set<int>st;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = nums[i]^nums[j];
                st.insert(val);
            }
        }

        int result = 0;
        for(int i=0;i<2048;i++){
            for(auto val : st){
                int ans = val^i;
                if(num_st.find(ans)!=num_st.end()){
                    result++;
                    break;
                }
            }
        }

        return result;
    }
};
