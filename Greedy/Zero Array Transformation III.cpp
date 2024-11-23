int result = 0;
int pref = 0;
i = 0;
while(i < n){
    pref += freq_cnt[i];
    
    for(auto k: mp[i]){
        pq.push(k);
    }

    int val = nums[i] - pref;
  
    if(val <= 0){
        i++;
        continue;
    }
    if(val > pq.size()) return -1;

    result += val;
    while(val > 0 && pq.size() > 0){
        int last = pq.top();
        if(last < i) return -1;
        pq.pop();
        freq_cnt[last+1] -= 1;
        pref++;
        val--;
    }
    i++;
}
return m - result;
