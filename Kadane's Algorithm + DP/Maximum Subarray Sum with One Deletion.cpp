class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int result = INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            result = max(result,arr[i]);
        }
        if(result <= 0)return result;
        vector<int>left(n,0);
        vector<int>right(n,0);
        int curSum = 0;
        for(int i=1;i<n;i++){
            curSum +=arr[i-1];
            if(curSum < 0){
                curSum = 0;
            } 
            left[i] = curSum;
        }
        curSum = 0;
        for(int i=n-2;i>=0;i--){
            curSum += arr[i+1];
            if(curSum < 0){
                curSum = 0;
            }
            right[i] = curSum;
        }

        for(int i=0;i<n;i++){
            result = max({result,left[i]+right[i],left[i]+right[i]+arr[i]});
        }

        return result;
    }
};
