class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>>result;

        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int n = occupiedIntervals.size();
        vector<int>cur_int = occupiedIntervals[0];
        for(int i=1;i<n;i++){
            if(cur_int[1]+1<occupiedIntervals[i][0]){
                result.push_back(cur_int);
                cur_int = occupiedIntervals[i];
                continue;
            }

            cur_int = {min(cur_int[0],occupiedIntervals[i][0]),max(cur_int[1],occupiedIntervals[i][1])};
        }
        result.push_back(cur_int);

        n = result.size();
        vector<vector<int>>final_result;
        for(int i=0;i<n;i++){
            if(result[i][1] < freeStart || result[i][0] > freeEnd){
                final_result.push_back(result[i]);
                continue;
            }

            if(result[i][0] < freeStart)final_result.push_back({result[i][0],freeStart-1});
            if(result[i][1] > freeEnd)final_result.push_back({freeEnd+1,result[i][1]});
        }

        return final_result;
    }
};
