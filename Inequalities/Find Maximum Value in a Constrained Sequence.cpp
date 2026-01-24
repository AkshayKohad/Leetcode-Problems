class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int>upper_bound(n,1e9);
        upper_bound[0] = 0;
        for(int i=0;i<restrictions.size();i++){
            int ind = restrictions[i][0];
            int max_val = restrictions[i][1];
            upper_bound[ind] = max_val;
        }

        for(int i=0;i<n-1;i++){
            upper_bound[i+1] = min(upper_bound[i+1],upper_bound[i]+diff[i]);
        }

        for(int i=n-2;i>=0;i--){
            upper_bound[i] = min(upper_bound[i],upper_bound[i+1]+diff[i]);
        }

        int result = 0;
        for(int i=0;i<n;i++){
            result = max(result,upper_bound[i]);
        }

        return result;
    }
};
