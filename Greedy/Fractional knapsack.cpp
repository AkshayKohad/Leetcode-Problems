#include <bits/stdc++.h>

static bool mycmp(pair<int,int>one,pair<int,int>two)
{
    double r1 = (double)one.second/(double)one.first;
    
    double r2 = (double)two.second/(double)two.first;
    
    return r1>r2;
}


double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    sort(items.begin(),items.end(),mycmp);
    
    int current_weight = 0;
    double max_val = 0;
    
    for(int i=0;i<n;i++)
    {
        if(current_weight + items[i].first <= w)
        {
            current_weight += items[i].first;
            max_val += items[i].second;
        }
        
        else{
            int remain = w - current_weight;
            max_val += ((double)items[i].second/(double)items[i].first) * (double)remain;
            break;
        }
    }
    
    
    return max_val;
    
}
