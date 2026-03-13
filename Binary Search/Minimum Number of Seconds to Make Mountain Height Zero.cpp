class Solution {
public:
    #define ll long long

    long long find_height(ll tlimit,ll hlimit,ll wtime){
        ll l = 0;
        ll r = hlimit;
        ll ans = -1;
        while(l<=r){
            ll mid = (r-l)/2 + l;

            ll res = mid*(mid+1);
            res = res/2;
            if(res<=tlimit/wtime){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
    bool check(ll timeLimit,int heightLimit,vector<int>&workerTimes){

        for(auto wtime : workerTimes){
            ll height_reduce = find_height(timeLimit,heightLimit,wtime);

            heightLimit -= height_reduce;

            if(heightLimit<=0)return true;
        }

       return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = 0;
        ll maxW = *max_element(workerTimes.begin(), workerTimes.end());
        ll r = maxW * (1LL * mountainHeight * (mountainHeight + 1))/2;
        ll ans = -1;

        while(l<=r){
            ll mid = (r-l)/2 + l;
            
            if(check(mid,mountainHeight,workerTimes)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
