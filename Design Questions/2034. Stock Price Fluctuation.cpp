class StockPrice {
public:
    
    map<int,int>time_price;
    
    set<pair<int,int>>price_time_pair;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(time_price.find(timestamp)!=time_price.end())
        {
            int val = time_price[timestamp];
            
            price_time_pair.erase({val,timestamp});
            
            time_price[timestamp] = price;
            
            price_time_pair.insert({price,timestamp});
        }
        
        else{
            time_price[timestamp] = price;
            
            price_time_pair.insert({price,timestamp});
        }
    }
    
    int current() {
        
       return  time_price.rbegin()->second;
    }
    
    int maximum() {
        
        return price_time_pair.rbegin()->first;
    }
    
    int minimum() {
        
        return price_time_pair.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
