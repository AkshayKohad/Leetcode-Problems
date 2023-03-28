class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
     
    int n = nums.size();
        
    sort(nums.begin(),nums.end());
        
    queue<int>q;
        
    for(int i=0;i<n;i++)
    {
        q.push(nums[i]);
    }
        
    int result = 0;
        
    int index = 0;    
    while(q.empty()==false)
    {
        int x = q.front();
        q.pop();
        if(x>nums[index])
        {
            result++;
            index++;
        }
    }
                
        return result;
        
    }
};
