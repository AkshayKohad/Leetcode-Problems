class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // finding val 2^n -1 because from 0 to 2^n -1 will  give all permutations of subset present in it
        int end = pow(2,n)-1;
        
        int start =0;
        vector<vector<int>>b;
        for(int i=start;i<=end;i++)
        {
            int k = i;
            vector<int>a;
            int count = 0;
            while(k!=0)
            {
                
                int bit = k&1;
                if(bit==1)
                {
                    a.push_back(nums[count]);
                }
                k = k>>1;
                count++;
            }
            
            b.push_back(a);
        }
        
        return b;
        
    }
};
