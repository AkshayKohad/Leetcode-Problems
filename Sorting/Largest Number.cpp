class Solution {
public:
    
    static bool mycmp(string f,string s)
    {        
        return f+s > s+f;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string>res;
        
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count++;
            string k = to_string(nums[i]);
            res.push_back(k);
        }
        
        if(count==nums.size())
            return "0";
        
        sort(res.begin(),res.end(),mycmp);
        
        string ans;
        
        for(int i=0;i<res.size();i++)
        {
            ans += res[i];
        }
        
        return ans;
    }
};
