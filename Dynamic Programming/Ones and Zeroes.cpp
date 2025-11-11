class Solution {
public:

    int solve(int i,int n, int m,int &sz,vector<pair<int,int>>&cnt_record,vector<vector<vector<int>>>&memo){
        if(i==sz){
            return 0;
        }

        if(memo[i][n][m] != -1)return memo[i][n][m];

        int cnt_1 = cnt_record[i].first;
        int cnt_0 = cnt_record[i].second;

        if(cnt_1 <= n && cnt_0 <= m){
            return memo[i][n][m] = max(solve(i+1,n,m,sz,cnt_record,memo), 1+solve(i+1,n-cnt_1,m-cnt_0,sz,cnt_record,memo));
        }else{
            return memo[i][n][m] = solve(i+1,n,m,sz,cnt_record,memo);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>cnt_record;

        for(auto str : strs){
            int cnt_1 = 0;
            int cnt_0 = 0;
            for(auto ch : str){
                if(ch == '0'){
                    cnt_0++;
                }else{
                    cnt_1++;
                }
            }

            cnt_record.push_back({cnt_1,cnt_0});
        }

        int sz = cnt_record.size();
        vector<vector<vector<int>>>memo(sz+1,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
        return solve(0,n,m,sz,cnt_record,memo);
    }
};
