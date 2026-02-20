class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        vector<int>conflict;
        vector<pair<int,int>>non_conflict;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==forbidden[i]){
                conflict.push_back(nums[i]);
            }else{
                non_conflict.push_back({nums[i],forbidden[i]});
            }
        }

        int max_conflicts = 0;
        sort(conflict.begin(),conflict.end());

        int i=0;
        int m = conflict.size();
        int val = -1;
        while(i<m){
            int cnt = 0;
            int j = i;
            while(j<m && conflict[j]==conflict[i]){
                j++;
                cnt++;
            }

            if(max_conflicts < cnt){
                max_conflicts = cnt;
                val = conflict[i];
            }
            i=j;
        }
        
        if(max_conflicts <= m/2)return m/2 + m%2;
        int remaining = m - max_conflicts;
        int result = remaining;
        max_conflicts = max_conflicts - remaining;
        int sz = non_conflict.size();
        for(int i=0;i<sz;i++){
            if(non_conflict[i].first != val && non_conflict[i].second != val){
                result++;
                max_conflicts--;
            }
            if(max_conflicts==0)break;
        }

        if(max_conflicts == 0)return result;
        return -1;
    }
};
