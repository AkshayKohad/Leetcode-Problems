class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        
        int score = 0;
        int res= 0;
        
        int i=0;
        int j = n-1;
        
        while(i<=j)
        {
            if(power<tokens[i])
            {
                if(score==0)
                {
                    break;
                }
                
                else{
                    power+=tokens[j];
                    score--;
                    j--;
                }
            }
            
            else{
                score++;
                power -=tokens[i];
                i++;
            }
            
            res = max(res,score);
        }
        
        return res;
    }
};
