How many states can we generate with x pigs and T tests?
Find minimum x such that (T+1)^x >= N

// Approach 1(Binary Search)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int number_of_test = minutesToTest/minutesToDie;

        // (test+1)^pigs >= buckets
        int l = 0;
        int r = 10;
        int ans = -1;
        while(l<=r){
            int mid = (l+r)/2;

            int expression_result = pow(number_of_test+1,mid);
            if(expression_result >= buckets){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
       return ans;
    }
};


// Approach 2(Simple Math)
class Solution {
public:

int poorPigs(int buckets, int poisonTime, int totalTime) {
    return ceil(log(buckets) / log(totalTime / poisonTime + 1));
}
};
