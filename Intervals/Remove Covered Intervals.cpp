class Solution {
public:
    static bool mycmp(vector<int>first,vector<int>second){
        if(first[0]==second[0])return first[1]>second[1];
        return first[0]<second[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycmp);
        vector<int>cur_interval = intervals[0];
        int cur_cnt = 1;
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(cur_interval[0] <= intervals[i][0] && cur_interval[1] >= intervals[i][1]){
                continue;
            }
            cur_interval = intervals[i];
            cur_cnt++;
        }

        return cur_cnt;
    }
};
