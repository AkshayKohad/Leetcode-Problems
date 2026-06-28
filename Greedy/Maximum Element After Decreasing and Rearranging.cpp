class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        int cur_val = arr[0];
        int res_val = arr[0];
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && cur_val==arr[j]){
                j++;
            }
            if(j==n)break;

            if(arr[j]-cur_val > 1){
                arr[j] = cur_val+1;
                cur_val += 1;
            }else{
                cur_val = arr[j];
            }

            i=j;
        }
        return cur_val;
    }
};
