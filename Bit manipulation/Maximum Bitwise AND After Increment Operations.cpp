class Solution {
public:

    #define ll long long

    int maximumAND(vector<int>& nums, int k, int m) {
        int ans = 0;

        for(int i=30;i>=0;i--){
            int target = ans | (1<<i);

            vector<int>costs; 

            for(auto val : nums){
                int cur = val;
                int cost = 0;

                for(int j=30;j>=0;j--){
                    if((target>>j)&1){
                        if(!((cur>>j)&1)){
                            int rem = cur%(1<<j);
                            int res = (1<<j);

                            int add_val = res-rem;
                            cur += add_val;
                            cost += add_val;
                        }
                    }
                }

                costs.push_back(cost);
            }

            sort(costs.begin(),costs.end());
            
            ll total = 0;

            for(int i=0;i<m;i++){
                total += costs[i];
            }

            if(total <= k){
                ans |= target;
            }
        }
        
        return ans;
    }

};
