class Solution {
public:
    #define mod 1000000007
    long long power(long long a,long long n){
        if(n==0)return 1;
        if(n==1)return a;

        if(n%2){
            long long res = a;
            long long ans = power(a,(n-1)/2);
            ans = (ans*ans)%mod;
            ans = (ans*res)%mod;
            return ans;
        }
        long long ans = power(a,n/2);
        ans = (ans*ans)%mod;
        return ans;
    }
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum += (long long)nums[i];
        }
        long long res_num = sum/k + (sum%k > 0 ? 1:0) -1;
        res_num = res_num%mod;
        long long res_result = ((res_num * (res_num+1))%mod * power(2ll,mod-2))%mod;
        return res_result; 
    }
};
