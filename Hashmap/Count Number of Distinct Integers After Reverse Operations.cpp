class Solution {
public:

void Reverse(int val,unordered_set<int>&result)
{
    int reversed_num = 0;
    int temp = val;

    while(temp!=0)
    {
        int remainder = temp%10;
        reversed_num = reversed_num*10 + remainder;

        temp = temp/10;
    }

    result.insert(reversed_num);
}
    int countDistinctIntegers(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int>result;

        for(int i=0;i<n;i++)
        {
            result.insert(nums[i]);
        }
        int count = n;
        for(int i=0;i<n;i++)
        {
            Reverse(nums[i],result);
        }

        return result.size();
    }
};
