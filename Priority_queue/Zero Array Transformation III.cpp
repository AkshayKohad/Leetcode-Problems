class Solution {
public:
   
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
        int prefix = 0;
        int n = nums.size();

        vector<int>freq_cnt(n+1,0);

        int i=0;
        priority_queue<int>pq;
        int m = queries.size();

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            mp[queries[i][0]].push_back(queries[i][1]);
        }

        int result = 0;
        int pref = 0;
        i=0;
        while(i<n){
            pref += freq_cnt[i];
        
            for(auto k:mp[i]){
                pq.push(k);
            }

            int val = nums[i]-pref;
          
            if(val<=0){
                i++;
                continue;
            }
            if(val > pq.size()) return -1;

            result+=val;
            while(val>0 && pq.size()>0){
                int last = pq.top();
                if(last<i)return -1;
                pq.pop();
                freq_cnt[last+1]-=1;
                pref++;
               
                val--;
            }
            i++;
        }
        //cout<<result<<endl;
        return m-result;

    }
};
