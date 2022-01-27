class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
          vector<string>a;
        //making ine universal map which will be having maximum count of occurence among all the words2 strings 
        unordered_map<char,int>universal;
        for(int i=0;i<words2.size();i++)
        {
            unordered_map<char,int>m;
            for(int j=0;j<words2[i].length();j++)
            {
                
                m[words2[i][j]]++;
            }
            
            for(auto x:m)
            {
              //counting max count of characters in universal map
                universal[x.first] = max(universal[x.first],m[x.first]);
            }
        }
        
        
        for(int i=0;i<words1.size();i++)
        {
             unordered_map<char,int>m;
            for(int j=0;j<words1[i].length();j++)
            {
                m[words1[i][j]]++;
            }
            int flag=1;
            for(auto x:universal)
            {
              // And then comparing that universal map with that of map of each words1 strings if it satisfies every condition then that string is added
                if(universal[x.first]>m[x.first])
                {
                 flag=0;
                    break;
                }
                 
            }
            
            if(flag==1)
            {
                a.push_back(words1[i]);
            }
        }
        
        return a;
    }
};
