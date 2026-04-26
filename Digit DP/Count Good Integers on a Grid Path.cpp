class Solution {
public:
    long long memo[16][10][2];

    void reset(){
        for(int i=0;i<16;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<2;k++){
                    memo[i][j][k] = -1;
                }
            }
        }
    }

    long long solve(int cur_index,string&num,int prev_digit,unordered_set<int>&indexes,int isTight){
        if(cur_index == num.length()){
            return 1;
        }

        if(memo[cur_index][prev_digit][isTight]!=-1)return memo[cur_index][prev_digit][isTight];

        int limit = num[cur_index]-'0';

        if(!isTight){
            limit = 9;
        }
        long long res = 0;
        for(int i=0;i<=limit;i++){
            int nextTight = isTight && (i==limit);

            if(indexes.find(cur_index)!=indexes.end()){
                if(prev_digit > i)continue;

                res += solve(cur_index+1,num,i,indexes,nextTight);
            }else{
                res += solve(cur_index+1,num,prev_digit,indexes,nextTight);
            }
        }


        return memo[cur_index][prev_digit][isTight] = res;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        string start = to_string(l);
        string end = to_string(r);

        int cur_len_end = end.length();
        int padding_req = 16-cur_len_end;
        string end_padding;
        while(padding_req--){
            end_padding.push_back('0');
        }
        end = end_padding + end;

        unordered_set<int>indexes;
        int cur_index = 0;
        indexes.insert(cur_index);
        for(auto direction : directions){
            if(direction == 'D'){
                cur_index += 4;
            }else{
                cur_index += 1;
            }

            indexes.insert(cur_index);
        }

        
        string prev_start = to_string(l-1);
        
        int cur_len_start = prev_start.length();
        string start_padding;
        padding_req = 16-cur_len_start;
        while(padding_req--){
            start_padding.push_back('0');
        }
        prev_start = start_padding + prev_start;

        reset();
        long long res_l = solve(0,prev_start,0,indexes,1);
        reset();
        long long res_r = solve(0,end,0,indexes,1);


        return res_r-res_l;
    }
};
