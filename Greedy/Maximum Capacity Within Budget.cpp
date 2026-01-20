class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        
        vector<pair<int,int>>cost_capacity;

        int n = costs.size();

        for(int i=0;i<n;i++){
            cost_capacity.push_back({costs[i],capacity[i]});
        }

        sort(cost_capacity.begin(),cost_capacity.end());

        vector<int>cost_sorted;
        vector<int>cap_sorted;

        for(int i=0;i<n;i++){
            cost_sorted.push_back(cost_capacity[i].first);
            cap_sorted.push_back(cost_capacity[i].second);
        }

        vector<int>cap_prefix(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                cap_prefix[i] = cap_sorted[i];
                continue;
            }else{
                cap_prefix[i] = max(cap_prefix[i-1],cap_sorted[i]);
            }
        }

        int result = 0;
        int index = lower_bound(cost_sorted.begin(),cost_sorted.end(),budget) - cost_sorted.begin() -1;

        if(index >= 0){
            result = cap_prefix[index];
        }

        for(int i=0;i<n;i++){
            int cur_cost = cost_sorted[i];

            if(cur_cost >= budget)break;

            int limit = budget-cur_cost;

            int ind = lower_bound(cost_sorted.begin(),cost_sorted.end(),limit) - cost_sorted.begin() -1;

            ind = min(ind,i-1);

            if(ind >= 0){
                result = max(result,cap_sorted[i] + cap_prefix[ind]);
            }
        }

        return result;
    }
};
