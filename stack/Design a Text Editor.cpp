class TextEditor {
public:
    stack<char>left;
    stack<char>right;
        
    TextEditor() {
        
    }
    
    void addText(string text) {
        
        for(int i=0;i<text.length();i++)
        {
            left.push(text[i]);
        }
    }
    
    int deleteText(int k) {
        
        int count = 0;
        
        while(left.empty()==false && k--)
        {
            count++;
            left.pop();
        }
        
        return count;
    }
    
    void restore(string &res)
    {
        for(int i=0;i<res.length();i++)
        {
            left.push(res[i]);
        }
    }
    
    
    string cursorLeft(int k) {
        
        while(left.empty()==false && k--)
        {
            char ch = left.top();
            
            left.pop();
            
            right.push(ch);
        }
        
        
        int count = 10;
        
        string res;
        
        while(left.empty()==false && count--)
        {
            res.push_back(left.top());
            left.pop();
            
        }
        
        reverse(res.begin(),res.end());
        
        restore(res);
        
        return res;
    }
    
    string cursorRight(int k) {
        while(right.empty()==false && k--)
        {
            char ch = right.top();
            
            right.pop();
            
            left.push(ch);
        }
        
        
        int count = 10;
        
        string res;
        
        while(left.empty()==false && count--)
        {
            res.push_back(left.top());
            left.pop();
            
        }
        
        reverse(res.begin(),res.end());
        
        restore(res);
       
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
