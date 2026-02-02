class Solution {
public:
    int countMonobit(int n) {
        n = n+1;
        for(int i=10;i>=0;i--){
            int val = (n>>i)&1;
            if(val==1)return i+1;
        }

        return 1;
    }
};
