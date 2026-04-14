class Solution {
public:
long long solve(int i,int j,int &robot_sz,int &factories_sz,vector<int>&robot,vector<int>&factories,vector<vector<long long>>&memo){
    if(i==robot_sz){
        return 0;
    }
    if(j==factories_sz){
        return LLONG_MAX;
    }

    if(memo[i][j]!=-1)return memo[i][j];

    long long res = LLONG_MAX;

    long long ans = solve(i+1,j+1,robot_sz,factories_sz,robot,factories,memo);

    if(ans != LLONG_MAX){
        ans += abs(robot[i]-factories[j]);
    }
    res = min(res,ans);
    res = min(res,solve(i,j+1,robot_sz,factories_sz,robot,factories,memo));

    return memo[i][j] = res;
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>factories;

        for(auto fac : factory){
            for(int i=0;i<fac[1];i++){
                factories.push_back(fac[0]);
            }
        }

        sort(robot.begin(),robot.end());
        sort(factories.begin(),factories.end());

        int robot_sz = robot.size();
        int factories_sz = factories.size();
        vector<vector<long long>>memo(robot_sz,vector<long long>(factories_sz,-1));
        return solve(0,0,robot_sz,factories_sz,robot,factories,memo);
    }
};
