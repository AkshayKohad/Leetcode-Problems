class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {

        //Note OR condition of x | y >= x
        int n = nums.size();
        // We will create boundary for each element to check it's validity in subarray

        stack<int>forwardStack;
        stack<int>backwardStack;

        vector<int>rightBoundary(n,n);
        vector<int>leftBoundary(n,-1);

        for(int i=0;i<n;i++){
            while(forwardStack.empty()==false && (nums[forwardStack.top()] | nums[i]) > nums[forwardStack.top()]){
                rightBoundary[forwardStack.top()] = i;
                forwardStack.pop();
            }
            forwardStack.push(i);
        }


        for(int i=n-1;i>=0;i--){
            while(backwardStack.empty()==false && (((nums[backwardStack.top()] | nums[i]) > nums[backwardStack.top()]) || (nums[backwardStack.top()] == nums[i]))){
                leftBoundary[backwardStack.top()] = i;
                backwardStack.pop();
            }
            backwardStack.push(i);
        }

        long long res = 0;
        for(int i=0;i<n;i++){
            res += 1LL * (i-leftBoundary[i])*(rightBoundary[i]-i);
        }

        return res;
    }
};
