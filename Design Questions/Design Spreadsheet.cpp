class Spreadsheet {
public:
    vector<vector<int>>excel;
    Spreadsheet(int rows) {
        excel.assign(rows,vector<int>(26,0));
    }
    
    bool check_sign(char sign){
        return (sign == '+'); 
    }
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        string rem = cell.substr(1,cell.length());
        int row = stoi(rem);
        excel[row-1][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        string rem = cell.substr(1,cell.length());
        int row = stoi(rem);
        excel[row-1][col] = 0;
    }
    
    int getValue(string formula) {   
        formula = formula.substr(1,formula.length());
        string operand1;
        char sign;
        string operand2;
        int n = formula.length();
        int i=0;
        while(i<n && check_sign(formula[i])==false){
            operand1.push_back(formula[i]);
            i++;
        }
        sign = formula[i];
        i++;
        while(i<n){
            operand2.push_back(formula[i]);
            i++;
        }
        int val1;
        int val2;
        if(operand1[0]>='A' && operand1[0]<='Z'){
            int col1 = operand1[0] - 'A';
            string rem1 = operand1.substr(1,operand1.length());
            int row1 = stoi(rem1);
            val1 = excel[row1-1][col1];
        }else{
            val1 = stoi(operand1);
            cout<<val1<<endl;
        }
        
        if(operand2[0]>='A' && operand2[0]<='Z'){
            int col2 = operand2[0] - 'A';
            string rem2 = operand2.substr(1,operand2.length());
            int row2 = stoi(rem2);
            val2 = excel[row2-1][col2];
        }else{
            val2 = stoi(operand2);
            cout<<val2<<endl;
        }
        
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
