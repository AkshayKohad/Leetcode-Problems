class Solution {
public:

void solve(int i,int &n,vector<int>&arr,int &max_chunks,vector<vector<int>>&res)
{
    if(i==n)
    {
      vector<int>resultant;

      for(int j=0;j<res.size();j++)
      {
          sort(res[j].begin(),res[j].end());

          resultant.insert( resultant.end(), res[j].begin(), res[j].end() );
      }


      for(int j=1;j<n;j++)
      {
         if(resultant[j]<resultant[j-1])  
         return;
      }
    
    if(max_chunks<res.size())
    max_chunks = res.size();

    }

   vector<int>temp;
    for(int j=i;j<n;j++)
    {
      temp.push_back(arr[j]);

      res.push_back(temp);
      solve(j+1,n,arr,max_chunks,res);
      res.pop_back();

    }
}
    int maxChunksToSorted(vector<int>& arr) {
        
        int max_chunks = 0;
        int n = arr.size();
      vector<vector<int>>res;
        solve(0,n,arr,max_chunks,res);

        return max_chunks;
    }
};
