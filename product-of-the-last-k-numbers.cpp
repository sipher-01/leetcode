class ProductOfNumbers {
    vector<int>arr;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        auto n = arr.end();
        int prod = 1;
        for(auto it=n-1; it>n-k-1; it--){
            prod = prod * (*it);
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */