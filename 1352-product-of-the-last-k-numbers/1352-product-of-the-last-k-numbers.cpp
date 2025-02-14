class ProductOfNumbers {
    private:
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct = {1};
    }
    void add(int num) {
         if (num == 0) {
            prefixProduct = {1};
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    int getProduct(int k) {
                int n = prefixProduct.size();
        if (k >= n) return 0; 
        return prefixProduct.back() / prefixProduct[n - 1 - k];
    }
};