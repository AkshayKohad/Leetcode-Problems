class NumberContainers {
public:
    
    
    //index-number
    unordered_map<int,int>index_list;
    
    // number-list of index having that number
    unordered_map<int,set<int>>number_occurence;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        if(index_list.find(index)==index_list.end())
        {
            index_list[index] = number;
            
            number_occurence[number].insert(index);
        }
        
        else{
            
            int num = index_list[index];
            
            if(number!=num)
            {
            index_list[index] = number;
            
            number_occurence[number].insert(index);
            
            number_occurence[num].erase(index);
            
            if(number_occurence[num].size()==0)
            {
                number_occurence.erase(num);
            }
            
            }    
        }
        
    }
    
    int find(int number) {
        
        if(number_occurence.find(number) == number_occurence.end())
            return -1;
        
        int result = *(number_occurence[number].begin());
        
        return result;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
