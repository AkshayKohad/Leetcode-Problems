class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        if(n==2){
            if(nums[0]>nums[1] || nums[0]<nums[1])return 2;
            return 1;
        }

        vector<int>monotonicity;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1])monotonicity.push_back(1);
            else if(nums[i]>nums[i+1])monotonicity.push_back(-1);
            else monotonicity.push_back(0);
        }

        vector<int>result;
        vector<int>start_parity;
        vector<int>end_parity;
        n = monotonicity.size();
        int i=0;
        while(i<n){
            if(monotonicity[i]==0){
                result.push_back(0);
                start_parity.push_back(0);
                end_parity.push_back(0);
                i++;
                continue;
            }
            int j=i;
            int cur = monotonicity[i]*(-1);
            int cnt = 0;
            int start = monotonicity[i];
            while(j<n && monotonicity[j]!=0){
                if(cur == monotonicity[j]){
                    break;
                }
                cur = monotonicity[j];
                j++;
                cnt++;

            }
            i=j;
            start_parity.push_back(start);
            end_parity.push_back(cur);
            result.push_back(cnt);
        }
        n = result.size();

        for(auto val : result)cout<<val<<" ";

        cout<<endl;
        int ans = 1;

        for(int i=0;i<n;i++){

            if(i+1<n && result[i+1]!=0){
                ans = max(ans,result[i]+result[i+1]);
            }else if(i+2<n && end_parity[i]!=start_parity[i+2]){
                ans = max(ans,result[i]+result[i+2]+1);
            }else{
                ans = max(ans,result[i]+1);
            }


            if(i-1>=0 && result[i-1]!=0){
                ans = max(ans,result[i]+result[i-1]);
            }else if(i-2>=0 && start_parity[i]!=end_parity[i-2]){
                ans = max(ans,result[i]+result[i-2]+1);
            }else{
                ans = max(ans,result[i]+1);
            }    
            
        }
        return ans;
    }
};
