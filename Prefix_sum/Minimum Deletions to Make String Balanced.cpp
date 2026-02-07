class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int cnt_a = 0;
        int cnt_b = 0;
        vector<int>count_b(n,0);
        vector<int>count_a(n,0);

        for(int i=0;i<n;i++){
            count_b[i] = cnt_b;
            if(s[i]=='b')cnt_b++;
        }

        for(int i=n-1;i>=0;i--){
            count_a[i]= cnt_a;
            if(s[i]=='a')cnt_a++;
        }
        int result = n;

        for(int i=0;i<n;i++){
            result = min(result,count_a[i]+count_b[i]);
        }
        return result;
    }
};
