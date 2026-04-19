class Solution {
public:
    int solve(int i,int &val,vector<int>&nums2,int &m){
        int l = i;
        int r = m-1;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;

            if(nums2[mid]>=val){
                l = mid+1;
                ans = mid;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int result = 0;
        for(int i=0;i<n;i++){

            int ans = solve(i,nums1[i],nums2,m);

            if(ans == -1)continue;

            result = max(result,ans-i);
        }
        return result;
    }
};
