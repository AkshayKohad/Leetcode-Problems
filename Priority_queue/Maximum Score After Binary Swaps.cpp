class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        int i=0;
        long long result = 0;
        while(i<n && s[i]=='1'){
            result += nums[i];
            i++;
        }
        if(i==n)return result;
        
        int j=n-1;
        while(j>=0 && s[j]=='0'){
            j--;
        }

        if(j<0)return 0;

        priority_queue<int>pq;
        while(i<=j){
            while(i<=j && s[i]=='0'){
                pq.push(nums[i]);
                i++;
            }
            int cnt = 0;
            while(i<=j && s[i]=='1'){
                pq.push(nums[i]);
                cnt++;
                i++;
            }

            while(cnt>0){
                result += pq.top();
                pq.pop();
                cnt--;
            }
        }
        return result;
    }
};
