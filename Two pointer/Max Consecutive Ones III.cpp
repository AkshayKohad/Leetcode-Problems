class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int index1;
	int index2;

	int max_length = 0;
	int i=0;
	int j=0;
	int no_of_zero = 0;

	while(j<n)
	{
		if(a[j]==0)
		{
			no_of_zero++;
			
		}

	

		while(no_of_zero > k)
		{
			if(a[i]==0)
			{
				no_of_zero--;
			}
			i++;
		}

		if(max_length<j-i+1)
		{
			max_length=j-i+1;
			index1 = i;
			index2 = j;
		}

		j++;
	}
   return max_length;
    }
};
