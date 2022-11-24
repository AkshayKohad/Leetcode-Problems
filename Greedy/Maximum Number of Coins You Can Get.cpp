class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
     sort(piles.begin(),piles.end(),greater<int>());
        
        
        int n = piles.size();
        int i=0;
        int j=n-1;
        
        
        int my_total = 0;
        while(i<j)
        {
            int alice = piles[i];
            int me = piles[i+1];
            int bob = piles[j];
            
            
            my_total += me;
            i = i+2;
            j--;
        }
        
        
        return my_total;
        
    }
};
