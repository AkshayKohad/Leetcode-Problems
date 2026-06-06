class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int>pq;
        int min_val = INT_MAX;
        for(auto num : nums){

            if(num%2 == 1){
                num = num*2;
            }
            pq.push(num);
            min_val = min(min_val,num);
        }

        int min_diff = INT_MAX;

        while(pq.size()>0){
            int cur = pq.top();
            pq.pop();

            min_diff = min(min_diff,cur-min_val);

            if(cur%2==0){
                int new_val = cur/2;
                min_val = min(new_val,min_val);

                pq.push(new_val);
            }else{
                break;
            }
        }

        return min_diff;
    }
};
