class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>status(n+1,0);

        vector<int>result(n);
        int pref_cnt = 0;
        for(int i=0;i<n;i++){
            int val_a = A[i];
            int val_b = B[i];

            if(status[val_a] == 0){
                status[val_a] = 1;
            }else{
                status[val_a] = 0;
                pref_cnt++;
            }

            if(status[val_b] == 0){
                status[val_b] = 1;
            }else{
                status[val_b] = 0;
                pref_cnt++;
            }

            result[i] = pref_cnt;
        }

        return result;
    }
};
