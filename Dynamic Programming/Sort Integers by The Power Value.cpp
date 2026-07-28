class Solution {
public:
    int solve(int num,unordered_map<int,int>&memo){
        if(num == 1)return 0;

        if(memo.find(num)!=memo.end()){
            return memo[num];
        }

        if(num%2){
            return memo[num] = solve(3*num+1,memo) + 1;
        }else{
            return memo[num] = solve(num/2,memo) + 1;
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>result;
        unordered_map<int,int>memo;
        for(int i=lo;i<=hi;i++){
            int ans = solve(i,memo);
            result.push_back({ans,i});
        }

        sort(result.begin(),result.end());
        return result[k-1].second;
    }
};

