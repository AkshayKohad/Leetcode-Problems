#include <bits/stdc++.h>

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
    
    stack<int>st;
    
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }
    
    while(st.size()>1)
    {
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        
        // if x knows y then x is not celebrity
        if(knows(x,y)==true)
        {
            st.push(y);
        }
        
        // else if x do not know y then y is not celebrity
        else
        {
            st.push(x);
        }
    }
    
    
    // remaining single value present in stack might be 
    // possiblity of being celebrity but we need to check
    int val = st.top();
    st.pop();
    
    for(int i=0;i<n;i++)
    {
        if(val==i)
            continue;
        
        // if any other knows val or val knows any other, 
        // then val is not celebrity
        if(knows(i,val)==false || knows(val,i)==true)
            return -1;
    }
    return val;
    
}
