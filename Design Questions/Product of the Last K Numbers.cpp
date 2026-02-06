class ProductOfNumbers {
public:
    vector<long long>product_prefix;
    vector<long long>prefix_zero;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(product_prefix.size()==0){
            if(num!=0){
                product_prefix.push_back(num);
                prefix_zero.push_back(0);
            }
            else{
                product_prefix.push_back(1);
                prefix_zero.push_back(1);
            }
        }else{
            if(num!=0){
                product_prefix.push_back(product_prefix.back()*(long long)num);
                prefix_zero.push_back(prefix_zero.back());
            }else{
                product_prefix.clear();
                product_prefix.push_back(1);
                prefix_zero.push_back(prefix_zero.back()+1);
            }
            
        }
    }
    
    int getProduct(int k) {
        if(k>product_prefix.size())return 0;
        else if(k==product_prefix.size()){
            if(prefix_zero.back()>0){
                return 0;
            }else{
                return product_prefix.back();
            }
        }else{
            int cnt = prefix_zero.back()-prefix_zero[prefix_zero.size()-k-1];
            if(cnt>0)return 0;

            return product_prefix.back()/product_prefix[product_prefix.size()-k-1];
        }
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

 
