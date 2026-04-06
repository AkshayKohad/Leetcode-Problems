class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int>sorted_nums = nums;
        sort(sorted_nums.begin(),sorted_nums.end());
        int n = nums.size();
        vector<int>prefix_changes(n,0);

        for(int i=1;i<n;i++){
            prefix_changes[i] = prefix_changes[i-1] + (nums[i-1]>nums[i] ? 1:0);
        }

        vector<int>divisors;
        for(int i=1;i*i<=n;i++){
            if(n%i != 0){
                continue;
            }
            divisors.push_back(i);
            int val = n/i;

            if(val == i)continue;

            divisors.push_back(val);
        }

        int result = 0;

        for(auto k : divisors){
            
            bool flag = true;
            for(int i=0;i<n;i=i+k){
                int drops = prefix_changes[i+k-1]-prefix_changes[i];
                if(nums[i+k-1] > nums[i])drops++;
                if(drops > 1){
                    flag = false;
                    break;
                }
                vector<int>temp;
                for(int j=i;j<i+k;j++){
                    temp.push_back(nums[j]);
                }
                sort(temp.begin(),temp.end());
                for(int j=i;j<i+k;j++){
                    if(temp[j-i]!=sorted_nums[j]){
                        flag = false;
                        break;
                    }
                }

                if(flag == false)break;

            }

            if(flag)result += k;
        }

        return result;
    }
};
