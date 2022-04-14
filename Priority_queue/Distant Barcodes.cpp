class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        for(int i=0;i<barcodes.size();i++)
        {
            mp[barcodes[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        
        
        for(auto res : mp)
        {
           pq.push({res.second,res.first});    
        }
        
        vector<int>a;
        pair<int,int>curr;
            
            a.push_back(pq.top().second);
           // pq.top().first--;
            curr = pq.top();
        curr.first--;
           pq.pop();
        for(int i=1;i<barcodes.size();i++)
        {
         a.push_back(pq.top().second);
           // pq.top().first--;
            
            if(curr.first==0)
            {
             curr = pq.top();
                curr.first--;
                pq.pop();
            }
            
            else{
                pair<int,int>temp;
                temp = pq.top();
                pq.pop();
                pq.push(curr);
                curr = temp;
                curr.first--;
            }
        }
        
        return a;
        
    }
};
