class AuctionSystem {
public:

    // item to pair of (Amount,userID)
    unordered_map<int,set<pair<int,int>>>item_record;

    // item#user key to price
    unordered_map<string,int>item_user_record;

    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        string key = to_string(itemId) + "#" + to_string(userId);
        int cur_bidAmount = -1;
        if(item_user_record.find(key)!=item_user_record.end()){
            cur_bidAmount = item_user_record[key];
        }
        item_user_record[key] = bidAmount;

        if(cur_bidAmount != -1){
            item_record[itemId].erase({cur_bidAmount,userId});
        }
        item_record[itemId].insert({bidAmount,userId});

    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        string key = to_string(itemId) + "#" + to_string(userId);
        
        int cur_bidAmount = item_user_record[key];
        
        item_user_record[key] = newAmount;

        item_record[itemId].erase({cur_bidAmount,userId});
        
        item_record[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        string key = to_string(itemId) + "#" + to_string(userId);
        
        int cur_bidAmount = item_user_record[key];
        
        item_user_record.erase(key);

        item_record[itemId].erase({cur_bidAmount,userId});
        
    }
    
    int getHighestBidder(int itemId) {
        
        if(item_record[itemId].size()==0)return -1;
        
        auto result = item_record[itemId].rbegin();

        return result->second;
    }
};

