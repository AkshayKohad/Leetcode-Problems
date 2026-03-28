Approach-1

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();

        unordered_map<int,int>mp_distinct;
        unordered_map<int,int>mp_count_m;

        int left_distinct = 0;
        int left_count = 0;
        int count_m = 0;

        long long res = 0;

        for(int right=0;right<n;right++){
            mp_distinct[nums[right]]++;

            while(mp_distinct.size()>k){
                mp_distinct[nums[left_distinct]]--;

                if(mp_distinct[nums[left_distinct]]==0){
                    mp_distinct.erase(nums[left_distinct]);
                }
                left_distinct++;
            }

            mp_count_m[nums[right]]++;
            if(mp_count_m[nums[right]] == m)count_m++;
            
            while(count_m>=k){
                if(mp_count_m[nums[left_count]]==m)count_m--;
                mp_count_m[nums[left_count]]--;
                left_count++;
            }

            if(left_count>left_distinct)res += left_count - left_distinct;
        }

        

        return res;
    }

    
};



Approach-2

class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, int k, int m) {
    unordered_map<int,int> hash;
    int l=0,unique=0,valid=0;
    int n=nums.size();
    ll ans=0;
    int extra=0;

    for(int r=0;r<n;r++){
        if(hash[nums[r]]==0) unique++;
        hash[nums[r]]++;
        if(hash[nums[r]]==m) valid++;

        while(unique>k){
            if(hash[nums[l]]==m) valid--;
            hash[nums[l]]--;
            if(hash[nums[l]]==0) unique--;
            l++;
            extra=0;
        }

        if(unique==k && valid==k){
            while(hash[nums[l]]>m){
                hash[nums[l]]--;
                l++;
                extra++;
            }
            ans+=extra+1;
        }
    }
    return ans;
}

    
};
