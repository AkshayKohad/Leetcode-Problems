class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.length();
        int left_a = n/2 - (n%2 == 0 ? 1:0);
        int right_a = n/2;

        while(left_a>=0 && right_a<n){
            if(a[left_a]!=a[right_a])break;
            left_a--;
            right_a++;
        }
        if(left_a<0)return true;

        int i=left_a;
        int j=right_a;
        while(i>=0){
            if(b[i]!=a[j])break;
            i--;
            j++;
        }
        if(i<0)return true;
        i = left_a;
        j = right_a;
        while(i>=0){
            if(a[i]!=b[j])break;
            i--;
            j++;
        }
        if(i<0)return true;

        int left_b = n/2 - (n%2 == 0 ? 1:0);
        int right_b = n/2;

        while(left_b>=0 && right_b<n){
            if(b[left_b]!=b[right_b])break;
            left_b--;
            right_b++;
        }
        if(left_b<0)return true;

        i=left_b;
        j=right_b;
        while(i>=0){
            if(b[i]!=a[j])break;
            i--;
            j++;
        }
        if(i<0)return true;
        i = left_b;
        j = right_b;
        while(i>=0){
            if(a[i]!=b[j])break;
            i--;
            j++;
        }
        if(i<0)return true;

        return false;
    }
};
