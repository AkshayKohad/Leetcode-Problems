class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>result;
        unordered_map<long long,int>mp;
        int limit =  cbrt(n);
        for(long long i=1;i<=limit;i++){
            for(long long j=i;j<=limit;j++){
                long long res = i*i*i + j*j*j;

                if(res>n)break;
                
                mp[res]++;
            }
        }

        for(auto val : mp){
            if(val.second>=2){
                result.push_back(val.first);
            }
        }

        sort(result.begin(),result.end());

        return result;
    }
};
