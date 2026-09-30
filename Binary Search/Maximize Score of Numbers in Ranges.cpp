class Solution {
public:
    bool check(int diff,vector<int>&start,int &d){
        int cur_val = start[0];
        int n = start.size();
        for(int i=1;i<n;i++){
            if(start[i]-cur_val>=diff){
                cur_val = start[i];
            }else if(start[i]+d-cur_val < diff){
                return false;
            }else{
                int min_diff = diff - (start[i]-cur_val);
                cur_val = start[i]+min_diff;
            }
        }

        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        int l = 0;
        int r = INT_MAX;
        int ans = -1;
        sort(start.begin(),start.end());
        while(l<=r){
            int mid = (r-l)/2 + l;

            if(check(mid,start,d)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;

    }
};
