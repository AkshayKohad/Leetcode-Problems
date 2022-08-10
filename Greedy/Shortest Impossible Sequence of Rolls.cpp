class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        
        
        
        // Make Maximum windows in such a way each window contains all numbers from 1 to k,  if x are number of such Window possible 
        // that means we can create all possible subsequence of maximum x length. So minimum length of subsequence which cannot create 
        // all subsequence is x+1 that is the answer
        
        
        
        unordered_set<int>s;
        
        int n = rolls.size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            s.insert(rolls[i]);
            
            if(s.size()==k)
            {
                count++;
                s.clear();
                
            }
            
            
        }
        
        return count+1;
    }
};
