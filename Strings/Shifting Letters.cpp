class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        
        int n = shifts.size();
        vector<long long int>sum(n);
        
        sum[n-1] = shifts[n-1];
        
        // using concept of prefix sum from ending
        for(int i=n-2;i>=0;i--)
        {
            sum[i] = sum[i+1] + shifts[i];
        }
        
        
        for(int i=0;i<n;i++)
        {
            long long int curr_val  = s[i] - 'a';
            
            long long int new_val = (curr_val + sum[i])%26;
            
            char ch = new_val + 'a';
            
            s[i] = ch;
        }
        
        return s;
    }
};
