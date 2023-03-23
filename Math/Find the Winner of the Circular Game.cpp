// This problem is known as Joshepus Problem
class Solution {
public:
    int solve(int n,int k)
    {
        if(n==1)
        return 0;

        int x = solve(n-1,k);

        int y = (x+k)%n;

        return y;
    }

    int findTheWinner(int n, int k) {
        // answer will be in 0 indexing so to make indexing from 1 we add 1
        return solve(n,k) + 1;
    }
};
