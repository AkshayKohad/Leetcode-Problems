class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();

        vector<int>prefix_xor(n);
        prefix_xor[0] = arr[0];

        for(int i=1;i<n;i++)
        {
            prefix_xor[i] = prefix_xor[i-1] ^ arr[i];
        }

        vector<int>result;
        for(int i=0;i<queries.size();i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            result.push_back(prefix_xor[right]^prefix_xor[left]^arr[left]);
        }

        return result;


    }
};
