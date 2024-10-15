#define ll long long

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        ll cnt = 0;
        ll val=1;
        
        while(val*2<k){
            val = val*2;
            cnt++;
        }
      
        if(k==1)
        return 'a';

        if(k==2){
           if(operations[0]==1) return 'b';
           else return 'a';
        }
        
        int count_ones = 0;

        while(k>1){
          if(k>val){
            k = k-val;
            count_ones += operations[cnt];
            cnt--;
            val=val/2;
          }
          else{
            val = val/2;
            cnt--;

          }
        }
        return 'a'+count_ones%26;
        
    }
};
