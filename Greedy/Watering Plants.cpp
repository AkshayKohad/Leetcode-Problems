class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int i=0;

        int n = plants.size();
        int cap = capacity;
        int ans = 0;
        while(i<n)
        {
            while(i<n && cap>=plants[i])
            {
                cap = cap-plants[i];
                i++;
            }

            if(i<n)
            {
             // we are not doing i+1 because the current ith value is pointing at next value 
             // for eg capacity is fulfilled till index=2 but after fullfilling it is pointing 
             // to next round that is 3rd index
             
            ans = ans + 2*(i);
            cap = capacity;
            }

            if(i==n)
            { 
                ans = ans + i;
                break;
            }
        }

        return ans;
    }
};
