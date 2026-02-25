class Solution {
public:
    #define ll long long
    long long minMoves(vector<int>& balance) {
        bool isNeg = false;
        ll neg_index = -1;
        ll sum_positive = 0;
        int n = balance.size();
        for(int i=0;i<n;i++){
            if(balance[i]<0){
                isNeg = true;
                neg_index = i;
            }else{
                sum_positive += balance[i];
            }
        }

        
        if(!isNeg)return 0;
        
        if(abs(balance[neg_index]) > sum_positive)return -1;

        ll left = (neg_index-1+n)%n;
        ll right = (neg_index+1)%n;
        ll result_moves = 0;
        ll req = abs(balance[neg_index]);
        while(left != neg_index){
            if(balance[left]>=req){
                result_moves += req*(min(abs(neg_index-left),n-abs(neg_index-left)));
                break;
            }else{
                req -= balance[left];
                result_moves += balance[left]*(min(abs(neg_index-left),n-abs(neg_index-left)));
                balance[left] = 0;        
                left = (left-1+n)%n;
            }
            
            if(req == 0)break;
            
            if(balance[right]>=req){
                result_moves += req*(min(abs(neg_index-right),n-abs(neg_index-right)));
                break;
            }else{
                req -= balance[right];
                result_moves += balance[right]*(min(abs(neg_index-right),n-abs(neg_index-right)));
                balance[right] = 0;
                right = (right+1)%n;
            }
        }

        return result_moves;
    }
};
