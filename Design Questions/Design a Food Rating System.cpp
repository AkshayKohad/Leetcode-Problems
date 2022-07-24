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





// Approach 2 is simple and easy to understand

class FoodRatings {
public:
    //food-rating
    map<string,int>f1;
    
    //food-cuisine
    map<string,string>f2;
    
    //cuisine-> set-> (rating,foods)
    map<string,set<pair<int,string>>>f3;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
     
        int n = foods.size();
        
        for(int i=0;i<n;i++)
        {
           f1[foods[i]] = ratings[i];
            
           f2[foods[i]]  = cuisines[i];
            
            f3[cuisines[i]].insert({-ratings[i],foods[i]});
        }
        
        
        
    }
    
    void changeRating(string food, int newRating) {
        
        f3[f2[food]].erase({-f1[food],food});
        
        f3[f2[food]].insert({-newRating,food});
        
        f1[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        
        return f3[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
