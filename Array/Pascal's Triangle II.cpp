class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>a;
        a.push_back(1);
        
        int row = rowIndex+1;
        
        int numerator = rowIndex;
        int denominator = 1;
        for(int i=2;i<=row;i++)
        {
            long long int val = a[a.size()-1];
            
           long long int res = (val * numerator)/denominator;
            numerator--;
            denominator++;
            
            a.push_back(res);
        }
        
        return a;
    }
};
