class Solution {
public:
    unordered_map<long long, pair<int,int>> memo;

    long long getKey(int w1, int w2, int f1, int f2, int idx) {
        long long key = w1;
        key = key * 21 + w2;
        key = key * 51 + f1;
        key = key * 51 + f2;
        key = key * 50 + idx;
        return key;
    }

    pair<int,int> solve(int waitTime1, int waitTime2, int fuel1, int fuel2,
              int cur_index, int &n, vector<int>& demand) {

        if (cur_index == n) return {0,0};
        
        long long key = getKey(waitTime1, waitTime2, fuel1, fuel2, cur_index);

        if (memo.count(key))
            return memo[key];

        pair<int,int>cur1 = {0,0};

        if (fuel1 >= demand[cur_index]) {
            int tempWait = max(0, waitTime2 - waitTime1);

            cur1 = solve(
                demand[cur_index],
                tempWait,
                fuel1 - demand[cur_index],
                fuel2,
                cur_index + 1,
                n,
                demand
            );

            cur1.second += 1;
            cur1.first = max(cur1.first,waitTime1);
            
        }

        pair<int,int>cur2 = {0,0};

        if (fuel2 >= demand[cur_index]) {
            int tempWait = max(0, waitTime1 - waitTime2);

            cur2 = solve(
                tempWait,
                demand[cur_index],
                fuel1,
                fuel2 - demand[cur_index],
                cur_index + 1,
                n,
                demand
            );

            cur2.second += 1;
            cur2.first = max(cur2.first,waitTime2);
        }

        pair<int,int>res = {0,0};
        if(cur1.second < cur2.second){
            res = cur2;
        }else if(cur1.second > cur2.second){
            res = cur1;
        }else{
            if(cur1.first <= cur2.first){
                res = cur1;
            }else{
                res = cur2;
            }
        }
        return memo[key] = res;
    }

    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        int n = demand.size();
        pair<int,int> ans = solve(0, 0, fuel[0], fuel[1], 0, n, demand);
        if(ans.second == 0 )return -1;
        return ans.first;
    }
};
