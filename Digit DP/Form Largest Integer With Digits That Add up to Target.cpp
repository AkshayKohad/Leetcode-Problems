class Solution {
public:

    string solve(vector<int>&cost,int target,int &mini,vector<string>&memo){
        if(target==0)return "";

        if(target < mini) return "0";

        if(memo[target]!="#")return memo[target];

        string res = "";
        for(int i=1;i<=9;i++){
            if(cost[i-1]>target)continue;

            string temp = solve(cost,target-cost[i-1],mini,memo);
            char ch = i + '0';

            if(temp=="0")continue;

            temp.push_back(ch);

            if(res.length()>temp.length())continue;
            else if(res.length()<temp.length()){
                res = temp;
                continue;
            }

            if(temp>res) res = temp;
        }
        if(res.length()==0)return "0";
        return memo[target] = res;
    }
    string largestNumber(vector<int>& cost, int target) {
        int mini = INT_MAX;

        for(auto val : cost){
            mini = min(mini,val);
        }

       vector<string>memo(target+1,"#");
       return solve(cost,target,mini,memo);
    }
};
