class Solution {
public:

 

  static bool mycmp(vector<int>first,vector<int>second)
  {
      return first[0]>second[0];
  }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        for(int i=0;i<score.size();i++)
        {
            score[i].insert(score[i].begin(),score[i][k]);
        }
        sort(score.begin(),score.end(),mycmp);

       for(int i=0;i<score.size();i++)
        {
            score[i].erase(score[i].begin());
        }
        

        return score;
    }
};
