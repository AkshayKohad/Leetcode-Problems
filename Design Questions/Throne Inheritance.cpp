class ThroneInheritance {
public:
    unordered_map<string,bool>dead;
    unordered_map<string,vector<string>>family;
    string root;
    ThroneInheritance(string kingName) {
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    void dfs(vector<string>&ans, string root){
        if(!dead[root]){
            ans.push_back(root);
        }
        for(string child : family[root]){
            dfs(ans, child);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(ans,root);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
