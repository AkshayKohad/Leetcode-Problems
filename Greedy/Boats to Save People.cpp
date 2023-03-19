class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
         int min_boats_count = 0;
        int n = people.size();
    
        int i=0;

        int j=n-1;

        while(i<j)
        {
           if(limit>=people[i]+people[j])
           {
               min_boats_count++;
               i++;
               j--;
           }

           else{
               min_boats_count++;
               j--;
           }
        }

        if(i==j)
        min_boats_count++;

        return min_boats_count;
    }
};
