class Solution {
public:
    long long coloredCells(int n) {
        
        // logic here is at each minute it increase in multiple of 4 
        // for eg for n minutes pattern goes like 1 , 1+4 = 5 , 5+8=13 , 13+12 = 25, 25+16 = 41, 41+20 = 61 and so on
        
        // so we use A.P for doing a=4, d=4  since it increases in progression of 4 => 1 (initial_box at 1st minute) + (n/2)*(2(4) + (n-1)*4)
        // it will be n*(2n+2)  now we put n=n-1 as we have 1st minute already with us
        // (n-1)*(2*(n-1) +2) => (n-1)*(2n), for time n, we will have result as 1 + (n-1)*(2n)
        
        return 1 + (long long)(n-1)*(2*n);
    }
};
