class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int>res;
        res.push_back(0);
        res.push_back(1);

        int power_of_2 = 1;
        for(int i=0;i<n-1;i++)
        {
           int size = res.size();
           power_of_2 = power_of_2*2;

           for(int j=size-1;j>=0;j--)
           {
               res.push_back(power_of_2+res[j]);
           }
        }

        return res;
    }
};
