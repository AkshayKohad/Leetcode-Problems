class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>res;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==1)continue;
            int cur_index = i;
            vector<int>temp;
            while(visited[cur_index]!=1){
                temp.push_back(arr[cur_index]);
                visited[cur_index] = 1;
                cur_index = (cur_index+k)%n;

            }
            res.push_back(temp);

        }

        long long ans = 0;
        for(int i=0;i<res.size();i++){
            sort(res[i].begin(),res[i].end());
            int sz = res[i].size();
            int median;
            if(sz%2){
                median = res[i][sz/2];
            }else{
                median = (res[i][sz/2] + res[i][sz/2-1])/2;
            }

            for(auto val : res[i]){
                ans += abs(median-val);
            }
             
        }

        return ans;
    }
};
