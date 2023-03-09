class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<int,char>mp;
        vector<int>char_mapping(26,-1);

        for(int i=0;i<order.length();i++)
        {
            int char_index = order[i] - 'a';

            char_mapping[char_index] = i+1;
           
           mp[i+1] = order[i];
        }

int j = order.size();
for(int i=0;i<26;i++)
{

    if(char_mapping[i]==-1)
    {
       char_mapping[i] = j+1;
        mp[j+1] = 'a' + i;
       j++;
    }
}
   vector<int>char_rank;

        for(int i=0;i<s.length();i++)
        {
            int char_index = s[i] - 'a';

            char_rank.push_back(char_mapping[char_index]); 
        }

        sort(char_rank.begin(),char_rank.end());

        string result;

        for(int i=0;i<char_rank.size();i++)
        {
            result.push_back(mp[char_rank[i]]);
        }

        return result;
    }
};
