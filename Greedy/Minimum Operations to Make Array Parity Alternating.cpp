class Solution {
public:
    vector<int>solve(vector<int>&nums,bool even){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int operations = 0;
        for(auto num:nums){
            if((even && num%2!=0) ||(!even && num%2==0)){
                operations++;
                mini = min(mini,num+1);
                maxi = max(maxi,num-1);
            }else{
                mini = min(mini,num);
                maxi = max(maxi,num);
            }

            even = !even;
        }
        return {operations,maxi-mini};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size();
        // Case when n == 1
        if(n == 1) return {0  , 0};

        //Case when all numbers are same
        unordered_set<int> st(nums.begin() , nums.end());
        if(st.size() == 1){
            return {(int)n / 2 , 1};
        }

        vector<int>res1 = solve(nums,true);
        vector<int>res2 = solve(nums,false);

        if(res1[0] == res2[0]){
            return res1[1] >= res2[1] ? res2 : res1;
        }else{
            return res1[0] > res2[0] ? res2 : res1;
        }
    }
};
