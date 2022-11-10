class Solution {
public:
    int rand10() {
        while(true){
            int r = (rand7()-1)*7 + rand7();
            if(r<=40) return r%10 + 1;
        }
    }
};
