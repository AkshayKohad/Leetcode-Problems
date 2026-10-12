class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int cur = 1;
        for(int i=1;i<=n;i++){
            int next = prev+cur;
            prev = cur;
            cur = next;
        }

        return cur;
    }
};
