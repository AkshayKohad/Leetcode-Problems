class FoodRatings {
public:
    map<string,int>food;
    map<string,map<int,set<string>>>cuisine_ratings;
    vector<string*>foods;
    vector<string*>cuisines;
    vector<int*>ratings;
    map<string,set<int>>max_rating;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        
        for(int i=0;i<f.size();i++)
        {
            foods.push_back(&f[i]);
            cuisines.push_back(&c[i]);
            ratings.push_back(&r[i]);
            max_rating[c[i]].insert(-r[i]);
        }
        
        for(int i=0;i<foods.size();i++)
        {
            food[*foods[i]] = i;
            
            cuisine_ratings[*cuisines[i]][-(*ratings[i])].insert(*foods[i]);
        }
        
        
    }
    
    void changeRating(string f, int newRating) {
        
        if(food.find(f)==food.end())
            return;
        
        int index = food[f];
        
         cuisine_ratings[*cuisines[index]][-(*ratings[index])].erase(f);
        
        if(cuisine_ratings[*cuisines[index]][-(*ratings[index])].size()==0)
        {
            cuisine_ratings[*cuisines[index]].erase(-(*ratings[index]));
            max_rating[*cuisines[index]].erase(-(*ratings[index]));
        }
        
        cuisine_ratings[*cuisines[index]][-newRating].insert(f);
        
      
        
        *ratings[index] = newRating; 
        
       
        max_rating[*cuisines[index]].insert(-newRating);
    }
    
    string highestRated(string c) {
        
        if(cuisine_ratings.find(c)==cuisine_ratings.end())
            return "";
        
        
      
        
        if(max_rating[c].size()==0)
            return "";
        
        
        string w  = *cuisine_ratings[c][*max_rating[c].begin()].begin();
        
        return w;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
