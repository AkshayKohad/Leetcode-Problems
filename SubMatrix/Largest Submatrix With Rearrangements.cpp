class Solution {
public:
    int find_largest_submatrix(vector<int>&prefix){
        int n = prefix.size();

        priority_queue<int>pq;
        for(auto num : prefix){
            pq.push(num);
        }

        int size = 0;
        int max_result = 0;
        while(pq.size()>0){
            int val = pq.top();
            pq.pop();
            size++;
            max_result = max(max_result,val*size);
        }
        return max_result;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>prefix(m,0);
        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)prefix[j]=0;
                else prefix[j]+=1;
            }

            result = max(result,find_largest_submatrix(prefix));
        }
        return result;
    }
};
