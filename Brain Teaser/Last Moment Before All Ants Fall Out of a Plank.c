int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize){

     int R = INT_MAX;
    
    for(int i=0;i<rightSize;i++)
    {
        if(R>right[i])
            R = right[i];
    }
    R = n-R;
    
    int L = INT_MIN;
    
    for(int i=0;i<leftSize;i++)
    {
        if(L<left[i])
            L = left[i];
    }
    
    if(rightSize==0 && leftSize==0)
        return 0;
    
    if(rightSize==0)
        return L;
    
    if(leftSize==0)
        return R;
    
    return fmax(L,R);
        
}
