class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long a = 1000;
        int commas = 1;

        while (a <= n) {
            long long b = a * 1000 - 1;
            long long count = min(n, b) - a + 1;

            res += count * commas;

            a *= 1000;
            commas++;
        }
        return res;
    }
};
