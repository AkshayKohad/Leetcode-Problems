#include <bits/stdc++.h> 
int subarraysXor(vector<int> &a, int x)
{
    
    unordered_map<int,int>m;
    int xor_res= 0;
    int count = 0;
    for(int i=0;i<a.size();i++)
    {
        xor_res ^= a[i];
        
        if(xor_res == x)
            count++;
        int req_res = xor_res ^ x; 
        if(m.find(req_res)!=m.end())
        {
            count += m[req_res];
        }
        
        m[xor_res]++;
    }
    
    return count;
    //    Write your code here.
}
