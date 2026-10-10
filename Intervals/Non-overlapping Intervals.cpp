class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> curInterval = intervals[0];
        int result = 0;

        for (int i = 1; i < n; i++) {
            if (curInterval[1] <= intervals[i][0]) {
                curInterval = intervals[i];
            } else {
                result++;
                if (intervals[i][1] < curInterval[1]) {
                    curInterval = intervals[i];
                }
            }
        }

        return result;
    }
};
