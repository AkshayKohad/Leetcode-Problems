class Solution {
public:
    #define mod 1000000007
    
    static bool mycmp(pair<int,int>&f,pair<int,int>&s){
        if(f.first == s.first){
            return f.second < s.second;
        }
        return f.first > s.first;
    }

    long long power(long long a, long long n){
        if(n==0)return 1;
        if(n==1)return a;

        if(n%2==0){
            long long ans = power(a,n/2);
            return (ans*ans)%mod;
        }else{
            long long ans = power(a,(n-1)/2);
            ans = (ans*ans)%mod;
            return (ans*a)%mod;
        }
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        
        int all_zeroes = 0;
        int all_ones = 0;

        vector<pair<int,int>>others;

        int n = nums1.size();

        for(int i=0;i<n;i++){
            int cnt_1 = nums1[i];
            int cnt_0 = nums0[i];

            if(cnt_1==0){
                all_zeroes += cnt_0;
            }else if(cnt_0==0){
                all_ones += cnt_1;
            }else{
                others.push_back({cnt_1,cnt_0});
            }
        }

        sort(others.begin(),others.end(),mycmp);

        long long cur_power = all_zeroes;
        long long result = 0;

        int m = others.size();
        for(int i=m-1;i>=0;i--){
            int cnt_1 = others[i].first;
            int cnt_0 = others[i].second;

            cur_power += cnt_0;
            long long val = power(2,cur_power);
            long long val_1 = (power(2,cnt_1) - 1 + mod)%mod;

            cur_power += cnt_1;

            result = (result + (val*val_1)%mod)%mod;
        }

        long long val_1 = (power(2,all_ones) - 1 + mod)%mod;
        long long val = power(2,cur_power);

        result = (result + (val*val_1)%mod)%mod;

        return result;
    }
};
