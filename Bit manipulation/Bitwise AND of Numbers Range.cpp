class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for(int i=0;i<=32;i++){
            int left_bit = left&1;
            int right_bit = right&1;

            if((left_bit == 1) && (left_bit==right_bit) && (left == right)){
                res += pow(2,i);
            }

            left = left>>1;
            right = right>>1;
        }

        return res;
    }
};


