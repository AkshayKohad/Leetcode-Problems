/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        
        vector<string>candidate_words;

        for(int i=0;i<words.size();i++)
        {
          candidate_words.push_back(words[i]);
        }

        while(1)
        {
          int n = candidate_words.size();
          string word = candidate_words[n/2];
          int match = master.guess(word);
 
           if(match == 6)
           return;

          vector<string>temp;

          for(int i=0;i<n;i++)
          {
            if(word == candidate_words[i])
            continue;

            int temp_match = 0;

            for(int j=0;j<6;j++)
            {
              if(word[j] == candidate_words[i][j])
              temp_match++;

            }

            if(temp_match == match)
             temp.push_back(candidate_words[i]);

          }

          candidate_words = temp;


        }
    }
};
