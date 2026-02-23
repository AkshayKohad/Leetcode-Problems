class Solution {
public:
    bool find_factors(long long num,vector<int>&factor){
        while(num>1){
            if(num%2==0){
                num = num/2;
                factor[0]++;
            }else if(num%3==0){
                num = num/3;
                factor[1]++;
            }else if(num%5==0){
                num = num/5;
                factor[2]++;
            }else{
                return false;
            }
        }
        return true;
    }
    void solve(int i,int &n,vector<vector<int>>&factors,vector<int>&k_factors,vector<int>&cur,long long &result){
        if(i==n){
            if(cur == k_factors){
                result++;
                return;
            }
            return;
        }

        solve(i+1,n,factors,k_factors,cur,result);

        
        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];

        solve(i+1,n,factors,k_factors,cur,result);

        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];
        
        
        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];

        solve(i+1,n,factors,k_factors,cur,result);
        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];
    }

    void solve_left(int i,int &n,vector<vector<int>>&factors,vector<int>&cur,map<vector<int>,long long>&mp){
        if(i==n){
            mp[cur]++;
            return;
        }

        solve_left(i+1,n,factors,cur,mp);
        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];

        solve_left(i+1,n,factors,cur,mp);
        
        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];
        
        
        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];

        solve_left(i+1,n,factors,cur,mp);

        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];
        
        
    }

    void solve_right(int i,int &n,vector<vector<int>>&factors,vector<int>&k_factors,vector<int>&cur,map<vector<int>,long long>&mp,long long &result){
        if(i==n){
            vector<int>need(3,0);
            need[0] = k_factors[0] - cur[0];
            need[1] = k_factors[1] - cur[1];
            need[2] = k_factors[2] - cur[2];

            if(mp.count(need))result += mp[need];
            
            return;
        }

        solve_right(i+1,n,factors,k_factors,cur,mp,result);
        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];

        solve_right(i+1,n,factors,k_factors,cur,mp,result);
        
        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];
        
        
        cur[0] -= factors[i][0];
        cur[1] -= factors[i][1];
        cur[2] -= factors[i][2];

        solve_right(i+1,n,factors,k_factors,cur,mp,result);

        cur[0] += factors[i][0];
        cur[1] += factors[i][1];
        cur[2] += factors[i][2];
    }
    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();
        
        vector<vector<int>>factors(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            find_factors(nums[i],factors[i]);
        }

        vector<int>k_factors(3,0);

        if(find_factors(k,k_factors)==false)return 0;
        vector<int>cur(3,0);
        long long result = 0;
        int mid = n/2;
        map<vector<int>,long long>mp;
        solve_left(0,mid,factors,cur,mp);
        cur = {0,0,0};
        solve_right(mid,n,factors,k_factors,cur,mp,result);

        return result;
    }
};
