#include<bits/stdc++.h>


int binary_search(vector<int>temp,int val)
{
  int l = 0;
    int r = temp.size()-1;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        
        if(temp[mid]==val)
            return mid;
        
        else if(temp[mid]<val)
            l = mid+1;
        
        else if(temp[mid]>val)
            r = mid-1;
    }
    
    return l;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>temp;
    
    temp.push_back(arr[0]);
    int len = 1;
    
    for(int i=1;i<n;i++)
    {
        if(temp.back()<arr[i])
        {
            temp.push_back(arr[i]);
            len++;
        }
        
        else{
            int index = binary_search(temp,arr[i]);
            
            temp[index] = arr[i];
        }
    }
    
    return len;
}
