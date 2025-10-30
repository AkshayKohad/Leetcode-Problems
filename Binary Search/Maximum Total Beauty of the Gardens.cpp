class Solution {
public:
    #define ll long long

    ll solve(ll index,ll n,vector<ll>&suffix,ll &newFlowers,vector<int>&flowers, ll target){

        if(newFlowers >= suffix[index]){
            ll result = flowers[index];
            ll cnt = n-index;
            ll rem_flower = newFlowers - suffix[index];
            ll div = rem_flower/cnt;
            if(result + div >= target-1) return target-1;
            return result + div;
        }else if(newFlowers < suffix[n-1]){
            return flowers[n-1]+newFlowers;
        }

        ll l = index;
        ll r = n-1;
        ll ans = -1;

        while(l<=r){
            ll mid = (l+r)/2;
            if(suffix[mid]>newFlowers){
                l = mid+1;
            }else{
                ans = mid;
                r = mid-1;
            }
        }

        ll result = flowers[ans];
        ll cnt = n-ans;
        ll rem_flower = newFlowers - suffix[ans];
        ll div = rem_flower/cnt;
        if(result + div >= target-1) return target-1;
        return result + div;

    }
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        // if all elements are greater than equal to target
        int cnt = 0;
        int n = flowers.size();

        for(auto flower : flowers){
            if(flower >= target)cnt++;
        }

        if(cnt==n)return (long long)cnt*full;

        sort(flowers.begin(),flowers.end(),greater<int>());

        stack<ll>flowers_planted;
        ll cnt_full_gardens = 0;

        long long result = 0;
        long long index = -1;
        for(int i=0;i<n;i++){
            if(flowers[i]>=target){
                cnt_full_gardens++;
                continue;
            }
            ll diff = target-flowers[i];

            if(diff <= newFlowers){
                flowers_planted.push(diff);
                cnt_full_gardens++;
                newFlowers -= diff;
            }else{
                break;
            }
            
        }

        
        
        vector<ll>suffix(n);
        suffix[n-1] = 0;

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + (flowers[i]-flowers[i+1])*(n-1-i);
        }

        if(cnt_full_gardens == n)
        result = cnt_full_gardens*full;
        else
        {
            ll partial_flowers = solve(cnt_full_gardens,n,suffix,newFlowers,flowers,target);
            result = cnt_full_gardens*full + partial_flowers*partial;
        }

        while(flowers_planted.empty()==false){
            newFlowers += flowers_planted.top();
            flowers_planted.pop();
            cnt_full_gardens--;
            int diff = target-1-flowers[cnt_full_gardens];

            
            ll partial_flowers = solve(cnt_full_gardens,n,suffix,newFlowers,flowers,target);
            result = max(result,cnt_full_gardens*full + partial_flowers*partial);
        }
        return result;

    }
};
