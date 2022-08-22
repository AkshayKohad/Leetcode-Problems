class MovieRentingSystem {
public:
    
    // list of unrented movies
    //map<shop,map<movie,price>>
    map<int,map<int,int>>unrented;
    
    // list of rented movies
    //map<shop,map<movie,price>>
    map<int,map<int,int>>rented;
    
    
    //List of all rented movies with format 
    //pair<price<pair<shop,movie>>
    set<pair<int,pair<int,int>>>price_details;
    
    
    //List of unrented movies mapped by movies
    // movies,set<pair<price,shop>>
    map<int,set<pair<int,int>>>unrented_search;
    
    int n;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        
        this->n =n;
        for(int i=0;i<entries.size();i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            
            unrented[shop][movie] = price;
            unrented_search[movie].insert({price,shop});
            
        }
    }
    
    vector<int> search(int movie) {
        vector<int>res;
        
        
        for(auto k:unrented_search[movie])
        {
            int price = k.first;
            int shop = k.second;
            
            res.push_back(shop);
            
            if(res.size()==5) break;
        }
        
        return res;
    }
    
    void rent(int shop, int movie) {
        
        if(unrented[shop].find(movie)==unrented[shop].end()) return;
        
        int price = unrented[shop][movie];
        
        unrented[shop].erase(movie);
        
        rented[shop][movie] = price;
        
        price_details.insert({price,{shop,movie}});
        
        unrented_search[movie].erase({price,shop});
    }
    
    void drop(int shop, int movie) {
        
        if(rented[shop].find(movie)==rented[shop].end())  return;
        
        
        int price = rented[shop][movie];
        
         rented[shop].erase(movie);
        
        unrented[shop][movie] = price;
        
        price_details.erase({price,{shop,movie}});
        
        unrented_search[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        
        vector<vector<int>>res;
        int l = 0;
        
        for(auto k : price_details)
        {
            pair<int,pair<int,int>>curr = k;
            
            int shop = curr.second.first;
            int movie = curr.second.second;
            
            res.push_back({shop,movie});
            
            
            if(res.size()==5)
                break;   
        } 
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
