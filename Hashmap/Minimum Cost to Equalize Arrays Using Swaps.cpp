class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>num1_mp;
        unordered_map<int,int>num2_mp;

        for(auto num : nums1){
            num1_mp[num]++;
        }

        for(auto num : nums2){
            num2_mp[num]++;
        }

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>result;
        for(auto val : num1_mp){
            int key = val.first;
            int cnt = val.second;

            int cnt2 = num2_mp[key];
            int total_cnt = cnt + cnt2;
            if(total_cnt % 2 == 1)return -1;

            num2_mp.erase(key);
            
            int diff = abs(cnt2-cnt);
            result.push_back(diff/2);
        }

        for(auto val : num2_mp){
            int key = val.first;
            int cnt = val.second;

            int cnt2 = num1_mp[key];
            int total_cnt = cnt + cnt2;
            if(total_cnt % 2 == 1)return -1;
            int diff = abs(cnt2-cnt);
            result.push_back(diff/2);
                
        }
        
        if(result.size()==1)return result[0];

        int ans = 0;
        int i=0;
        int j=result.size()-1;

        while(i<j){
            int val1 = result[i];
            int val2 = result[j];

            if(val1 > val2){
                ans += val2;
                result[i] -= val2;
                j--;
            }else if(val1 < val2){
                ans += val1;
                result[j] -= val1;
                i++;
            }else{
                ans += val2;
                result[i] = 0;
                result[j] = 0;
                i++;
                j--;
            }
        }
        if(i==j)ans += result[i];
        return ans;
    }
};
