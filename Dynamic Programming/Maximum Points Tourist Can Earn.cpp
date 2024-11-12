class Solution {
public:
    int solve(int day,int start_state,int cur_city,int &n,int &k,vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,vector<vector<vector<int>>>&memo){
        if(day==k)return 0;
        if(memo[day][start_state][cur_city]!=-1)return memo[day][start_state][cur_city];
        if(start_state){
            int res = 0;
            for(int i=0;i<n;i++){
                res = max(res,solve(0,0,i,n,k,stayScore,travelScore,memo));
            }
            return memo[day][start_state][cur_city] = res;
        }else{
            int res = 0;
            
            for(int i=0;i<n;i++){
                if(i==cur_city)continue;
                
                res = max(res,travelScore[cur_city][i]+solve(day+1,0,i,n,k,stayScore,travelScore,memo));
            }

            res = max(res,stayScore[day][cur_city]+solve(day+1,0,cur_city,n,k,stayScore,travelScore,memo));
            return memo[day][start_state][cur_city] = res;
        }
        
    }

    
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<vector<int>>>memo(k+1,vector<vector<int>>(2,vector<int>(n+1,-1)));
        return solve(0,1,0,n,k,stayScore,travelScore,memo);
    }
};
