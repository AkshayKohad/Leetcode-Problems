

//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void solve(stack<int>&st,stack<int>&s,bool flag,int &val)
{
  if(st.empty()==true &&  flag == false)
      return;
    
    if(flag==false)
    {
        int val = st.top();
        st.pop();
        
        solve(st,s,true,val);
    }
    
    else{
        if(s.empty()==true || s.top()<=val)
        {
            s.push(val);
            solve(st,s,false,val);
        }
        
        else if(s.top()>val)
        {
            int temp = s.top();
            st.push(temp);
            s.pop();
            solve(st,s,true,val);
        }
    }
    
    return;
}


void sortStack(stack<int> &st)
{
	// Write your code here
    stack<int>s;
    bool flag = false;
    int val=0;
    solve(st,s,flag,val);
    
    st = s;
}
