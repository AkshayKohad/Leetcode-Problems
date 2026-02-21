class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>mod_0;
        vector<int>mod_1;
        vector<int>mod_2;

        for(auto num : nums){
            if(num%3==0){
                mod_0.push_back(num);
            }else if(num%3==1){
                mod_1.push_back(num);
            }else{
                mod_2.push_back(num);
            }
        }

        sort(mod_0.begin(),mod_0.end());
        sort(mod_1.begin(),mod_1.end());
        sort(mod_2.begin(),mod_2.end());

        int max_result = 0;

        if(mod_0.size()>=3){
            int n = mod_0.size();
            max_result = max(max_result,mod_0[n-1]+mod_0[n-2]+mod_0[n-3]);
        }
        if(mod_1.size()>=3){
            int n = mod_1.size();
            max_result = max(max_result,mod_1[n-1]+mod_1[n-2]+mod_1[n-3]);
        }
        if(mod_2.size()>=3){
            int n = mod_2.size();
            max_result = max(max_result,mod_2[n-1]+mod_2[n-2]+mod_2[n-3]);
        }

        if(mod_0.size()>=1 && mod_1.size()>=1 && mod_2.size()>=1){
            max_result = max(max_result,mod_2.back()+mod_1.back()+mod_0.back());
        }
        return max_result;
    }
};
