class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,double>>workers;
        int n = quality.size();
        for(int i=0;i<n;i++){
            double cur_quality = quality[i];
            double cur_wage = wage[i];
            double rate = cur_wage/cur_quality;
            workers.push_back({rate,cur_quality});
        }
        sort(workers.begin(),workers.end());
        priority_queue<double>pq;
        double quality_sum = 0.0;
        double res_cost = DBL_MAX;
        for(auto worker : workers){
            quality_sum += worker.second;
            pq.push(worker.second);

            if(pq.size()>k){
                quality_sum -= pq.top();
                pq.pop();
            } 
            if(pq.size()==k){
                res_cost = min(res_cost,quality_sum*worker.first);
            }
        }
        return res_cost;
    }
};
