class FoodRatings {
public:
    map<string,string> c;
    map<string,int> f;
    map<string,set<pair<int,string>>> cr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            f[foods[i]]=ratings[i];
        }
        for(int i=0;i<cuisines.size();i++)
        {
            c[foods[i]]=cuisines[i];
            cr[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine=c[food];
        int rating=f[food];
        cr[cuisine].erase({-rating,food});
        cr[cuisine].insert({-newRating,food});
        f[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return cr[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */