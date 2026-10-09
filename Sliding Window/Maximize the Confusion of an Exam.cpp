class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0;
        int j=0;
        int cnt_true = 0;
        int cnt_false = 0;
        int n = answerKey.length();
        int result = 0;
        while(j<n){
            answerKey[j] == 'T' ? cnt_true++ : cnt_false++;
            j++;
            while(i<j && min(cnt_true,cnt_false)>k){
                answerKey[i] == 'T' ? cnt_true-- : cnt_false--;
                i++;
            }

            result = max(result,cnt_true + cnt_false);
        }
        return result;
    }
};
