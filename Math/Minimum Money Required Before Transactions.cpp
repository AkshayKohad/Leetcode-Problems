class Solution {
public:
    
    #define ll long long
    long long minimumMoney(vector<vector<int>>& transactions) {
        
        ll n = transactions.size(); 
        ll res = 0;
        
        ll ans = 0;
        for(ll i=0;i<n;i++)
        {
            ll price = transactions[i][0];
            ll cashback = transactions[i][1];
            
            if(price>cashback)
            {
                res += price-cashback;
                
                ans = max(ans,cashback);
            }
            
            else{
                ans = max(ans,price);
            }
        }
        
        return res + ans;
    }
};
