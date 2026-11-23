class ProductOfNumbers {
public:
    vector<int> pfx;
    int size;

    ProductOfNumbers() {
        size = -1;
    }
    
    void add(int num) {
        if (size == -1 && num != 0) {
            pfx.push_back(num);
            size++;
        }
        else {
            if (num == 0) {
                pfx = {};
                size = -1;
            }
            else {
                pfx.push_back(pfx[size] * num);
                size++;
            }
        }
    }
    
    int getProduct(int k) {
        if (k > size+1)
            return 0;
        return (k == size+1) ? pfx[size] : pfx[size] / pfx[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
