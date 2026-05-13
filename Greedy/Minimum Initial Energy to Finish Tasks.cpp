class Solution {
public:
    static bool mycmp(pair<int,int>&f,pair<int,int>&s){
        int diff_1 = f.second-f.first;
        int diff_2 = s.second-s.first;

        return diff_1>diff_2;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>>res;
        int n = tasks.size();
        int result = 0;
        for(int i=0;i<n;i++){
            pair<int,int>cur = make_pair(tasks[i][0],tasks[i][1]);
            res.push_back(cur);
            result += tasks[i][0];
        }
        sort(res.begin(),res.end(),mycmp);
        int cur_res = result;
        for(int i=0;i<n;i++){
            pair<int,int>cur = res[i];

            if(cur_res < cur.second){
                result += cur.second-cur_res;
                cur_res = cur.second;
                cur_res -= cur.first;
            }else{
                cur_res -= cur.first;
            }
        }

        return result;
    }
};

