maxProfit(const vector<int> &a) {

    long long int profit = 0;

    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])
        profit += a[i]-a[i-1];
    }

    return profit;
}
