class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10)return n;

        vector<int>digits;
        int result = n;
        while(n>0){
            int rem = n%10;
            digits.push_back(rem);
            n = n/10;
        }
        
        reverse(digits.begin(),digits.end());
       
        bool isdrop = false;
        int ind = -1;
        for(int i=1;i<digits.size();i++){
            if(digits[i]<digits[i-1]){
                isdrop = true;
                ind = i-1;
                break;
            }
        }
        if(!isdrop)return result;

        for(int i=ind+1;i<digits.size();i++)
        digits[i]=9;

        int j=ind;
        
        while(j-1>=0 && digits[j]==digits[j-1]){
            digits[j] = 9;
            j--;
        }
        digits[j]--;
        int answer = 0;
        long long mul = 1;
        for(int i=digits.size()-1;i>=0;i--){
            int cur_val = digits[i]*mul;
            answer += cur_val;
            mul *= 10;
        }
        return answer;
        
    }
};
