class Solution {
public:

    int solve(int i,int &m,vector<int>&toppingCosts,int &target,int cost,vector<vector<int>>&memo){
        if(i==m)return cost;

        if(memo[i][cost]!=-1)return memo[i][cost];

        int not_selected = solve(i+1,m,toppingCosts,target,cost,memo);
        int selected = solve(i+1,m,toppingCosts,target,cost+toppingCosts[i],memo);
        int selected_2 = solve(i+1,m,toppingCosts,target,cost+2*toppingCosts[i],memo);
        int not_selected_val = abs(target-not_selected);
        int selected_val = abs(target-selected);
        int selected_2_val = abs(target-selected_2);

        vector<pair<int,int>>res_selected;
        res_selected.push_back({not_selected_val,not_selected});
        res_selected.push_back({selected_val,selected});
        res_selected.push_back({selected_2_val,selected_2});

        sort(res_selected.begin(),res_selected.end());

        return memo[i][cost] = res_selected[0].second;

    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        
        int n = baseCosts.size();
        int m = toppingCosts.size();

        int result = -1;

        for(int i=0;i<n;i++){
           vector<vector<int>>memo(m,vector<int>(200001,-1));
           int ans = solve(0,m,toppingCosts,target,baseCosts[i],memo);
           if(result==-1){
                result = ans;
                continue;
           }

            int result_diff = abs(target-result);
            int ans_diff = abs(target-ans);

            if(result_diff>ans_diff)result = ans;
            else if(result_diff==ans_diff)result = min(result,ans);
        }
        return result;
    }
};
