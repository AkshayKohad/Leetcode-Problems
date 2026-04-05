class Solution {
public:
    #define ll long long
    pair<int,ll> solve(int i,int &n,vector<int>&visited,vector<pair<int,ll>>&memo,vector<ll>&cost){
        if(i>=n-1){
            return {0,0};
        }

        if(visited[i]==1)return memo[i];

        visited[i] = 1;
        pair<int,ll>skip = solve(i+1,n,visited,memo,cost);

        pair<int,ll>take = solve(i+2,n,visited,memo,cost);

        pair<int,ll>temp = {1+take.first,cost[i]+take.second};

        if(temp.first > skip.first){
            return memo[i] = temp;
        }else if(temp.first < skip.first){
            return memo[i] = skip;
        }else{
            if(temp.second > skip.second){
               return memo[i] = skip;
            }else{
               return memo[i] = temp;
            }
        }

        return memo[i];
    }
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<ll>cost(n,0);
        for(int i=1;i<n-1;i++){
            int maxi = max(nums[i-1],nums[i+1]);
            if(maxi>=nums[i]){
                cost[i] = maxi-nums[i]+1;
            }
        }

        vector<pair<int,ll>>memo(n,{0,0});
        vector<int>visited(n,0);

        return solve(1,n,visited,memo,cost).second;
    }
};
