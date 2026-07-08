class Solution {
public:
    #define mod 1000000007
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long>pref_non_zero(n,0);
        pref_non_zero[0] = (s[0]=='0' ? 0 : 1);

        vector<long long>pref_digit_sum(n,0);
        pref_digit_sum[0] = s[0]-'0';

        vector<long long>pref_res_sum(n,0);
        pref_res_sum[0] = s[0]-'0';
        for(int i=1;i<s.length();i++){
            pref_non_zero[i] = pref_non_zero[i-1] + (s[i]=='0' ? 0 : 1);
            pref_digit_sum[i] = pref_digit_sum[i-1] + s[i]-'0';
            pref_res_sum[i] = (s[i]-'0' == 0 ? pref_res_sum[i-1] : ((pref_res_sum[i-1]*10)%mod + s[i]-'0' )%mod);
        }

        vector<long long>pow10(n+1,0);
        pow10[0] = 1;
        for(int i=1;i<n;i++){
            pow10[i] = (pow10[i-1]*(long long)10)%mod;
        }

        vector<int>result;

        for(auto query : queries){
            int l = query[0];
            int r = query[1];
            cout<<pref_res_sum[r]<<endl;
            int digit_diff = pref_non_zero[r] - (l-1 >= 0 ? pref_non_zero[l-1] : 0);
            int res_sum = pref_res_sum[r]; 
            long long digit_sum = pref_digit_sum[r] - (l-1 >= 0 ? pref_digit_sum[l-1] : 0);
            long long ans = res_sum - (l-1 >= 0 ? (pref_res_sum[l-1]*pow10[digit_diff])%mod : 0);
            ans = (ans+mod)%mod;
            ans = (ans*digit_sum)%mod;
            result.push_back(ans);
        }

        return result;
    }
};

//Number non-zero numbers;
// sum of digits
// values
