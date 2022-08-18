// Only numbers which are square of some number will be switched on after all operations


class Solution {
public:
    int bulbSwitch(int n) {
        int i=1;
        
        while(i*i<=n)
        {
            i++;
        }
        
        return i-1;
    }
};
