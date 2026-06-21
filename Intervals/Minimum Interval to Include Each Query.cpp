class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int>result(n);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<pair<int,int>>sorted_query;
        for(int i=0;i<n;i++){
            sorted_query.push_back({queries[i],i});
        }
        sort(sorted_query.begin(),sorted_query.end());
        sort(intervals.begin(),intervals.end());
        int m = intervals.size();
        int int_ind = 0;
        int query_ind = 0;
        
        for(int i=0;i<n;i++){
            while(int_ind<m && intervals[int_ind][0] <= sorted_query[i].first){
                int len = intervals[int_ind][1]-intervals[int_ind][0]+1;
                pq.push({len,intervals[int_ind][0],intervals[int_ind][1]});
                int_ind++;
            }

            while(pq.size()>0 && pq.top()[2]<sorted_query[i].first){
                pq.pop();
            }

            int res = -1;
            if(pq.size()>0){
                res = pq.top()[0];
            }
            result[sorted_query[i].second] = res;
        }
        return result;
    }
};
