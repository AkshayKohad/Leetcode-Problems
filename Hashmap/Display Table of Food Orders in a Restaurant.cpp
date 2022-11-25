class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<string>item_record;
        
        int n = orders.size();
        
        map<int,map<string,int>>table_record;
        
       // set<int>table_seq;
        for(int i=0;i<n;i++)
        {
            string person = orders[i][0];
            
            string table = orders[i][1];
            
            string item_name = orders[i][2];
            
           int num = stoi(table);
            
           // table_seq.insert(num);
            table_record[num][item_name]++;
            item_record.insert(item_name);
        }
        
        vector<vector<string>>res;
        
        vector<string>t;
        
        t.push_back("Table");
        
        for(auto w:item_record)
        {
            t.push_back(w);
        }
        
        res.push_back(t);
        
        for(auto w:table_record)
        {
            int table_number = w.first;
            
            vector<string>temp;
            temp.push_back(to_string(table_number));
            
            for(auto m:item_record)
            {
               int x = table_record[table_number][m];
               
                string query = to_string(x);
                
               temp.push_back(query); 
            }
            
            res.push_back(temp);
        }
        
        
        return res;
    }
};
