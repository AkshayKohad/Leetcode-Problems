class Solution {
public:
    int numSteps(string s) {
        vector<int>ones;
        vector<int>zeros;
        int n = s.length();

        int i=0;
        while(i<n && s[i]=='0'){
            i++;
        }
        int j=0;

        while(i<n){
            
            int cur_cnt = 0;
            while(i<n && s[i]=='1'){
                cur_cnt++;
                i++;
            }
            if(cur_cnt>0)
                ones.push_back(cur_cnt);
            cur_cnt = 0;
            while(i<n && s[i]=='0'){
                cur_cnt++;
                i++;
            }
            if(cur_cnt>0){
                zeros.push_back(cur_cnt);
            }    
        }



        if(ones.size()==1){
            if(zeros.size()==0){
                if(ones[0]>1)
                    return ones[0]+1;
                else
                    return 0;
                
            }else{
                if(ones[0]>1)
                    return zeros[0]+ones[0]+1;
                else
                    return zeros[0];    
            }
        }

        int result = 0;
        
        while(ones.size()>0){
            if(ones.size()==zeros.size()){
                result += zeros.back();
                zeros.pop_back();
            }else{
                if(zeros.size()==0){
                    if(ones.back()==1)break;
                    else result += 1+ones.back();

                    ones.pop_back();
                }else{
                    // Adding 1
                    result += 1;
                    int cnt_1 = ones.back();
                    ones.pop_back();
                    if(zeros.back()==1){
                        zeros.pop_back();
                        int val = ones.back();
                        ones.pop_back();
                        ones.push_back(val+1);
                        zeros.push_back(cnt_1);
                    }else{
                        int cnt_0 = zeros.back();
                        zeros.pop_back();
                        ones.push_back(1);
                        zeros.push_back(cnt_0-1);
                        zeros.push_back(cnt_1);
                    }

                }
            }
        }

        return result;
    }
};
