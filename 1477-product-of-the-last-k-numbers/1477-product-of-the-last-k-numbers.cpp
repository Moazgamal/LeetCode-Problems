class ProductOfNumbers {
public:

vector<long long>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
        {
            v.clear();return ;
        }
       if(v.size() == 0)
       {
            v.push_back(num); return;
       }
       v.push_back(v[v.size()-1]*num);

    }
    
    int getProduct(int k) {
        if(v.size()<k)
            return 0; 

        if(v.size()==k)
            {
                return (int)v[v.size()-1];
            }
            return (int)v[v.size()-1]/(int)v[v.size()-k-1];
        return (int)v[v.size()-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */