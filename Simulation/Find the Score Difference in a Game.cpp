class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int player_1 = 0;
        int player_2 = 0;
        int is_active = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                is_active = 1-is_active;
            }
            if((i+1)%6 == 0){
                is_active = 1-is_active;
            }

            if(is_active){
                player_2 += nums[i];
            }else{
                player_1 += nums[i];
            }
        }

        return player_1 - player_2;
    }
};
