class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      
     int n = skill.size();
     sort(skill.begin(),skill.end());

     int i = 0;
     int j = n-1;
     
     int value = skill[0] + skill[n-1];
     long long res = 0;
     while(i<j)
     {
           if(skill[i]+skill[j]!=value)
           return -1;

           res = res + skill[i]*skill[j];

           i++;
           j--;
     }


     return res;   
    }
};
