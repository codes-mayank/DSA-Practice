class ProductOfNumbers {
public:
    vector<long long>arr;
    ProductOfNumbers() {
        arr.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            arr.clear();
            arr.push_back(1);
        }
        else {
            arr.push_back(arr.back() * num);
        }
    }
    
    int getProduct(int k) {
        int size = arr.size();
        if (k>=size) return 0;
        return arr[size-1] / arr[size-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */