class Solution {
public:
  int maxConsecutiveAnswers(string answerkey, int k) 
    {
        int i=0;
        int count=0;
        int maximum=0;
        //  maximum substring of 'T' which contains k 'F'
        for(int j=0;j<answerkey.size();j++)
        {
            if(answerkey[j]=='F')
                count++;
            if(count<=k) // why <=k is beacuse we can perform at most k operation
            {
                maximum=max(maximum, (j-i+1));
            }
            else if(count>k)
            {
                while(count>k)
                {
                    if(answerkey[i]=='F') // before moving the window check if it first element is F ,to decrease the count 
                    {
                        count--;
                    }
                    i++;
                }
            }
        }
        i=0;
        count=0;
        //maximum  substring of 'F' which contains k 'T'
         for(int j=0;j<answerkey.size();j++)
        {
            if(answerkey[j]=='T')
                count++;
            if(count<=k)
            {
                maximum=max(maximum, (j-i+1));
            }
            else if(count>k)
            {
                while(count>k)
                {
                    if(answerkey[i]=='T')
                    {
                        count--;
                    }
                    i++;
                }
            }
        }
        return maximum;
    }
};
