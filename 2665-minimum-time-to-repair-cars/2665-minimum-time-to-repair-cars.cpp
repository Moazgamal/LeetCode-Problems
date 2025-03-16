class Solution {
    bool fn(long long mid, vector<int> &ranks, int cars)
    {
        for(int i = 0; i< ranks.size(); i++)
        {
            long long carsN = floor(sqrt(mid/(long long)ranks[i]));
            cars -= carsN;
            if(cars<=0)
                return true;
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {

        long long ans = 0; 
        long long start = 1; 
        long long end = *std::max_element(ranks.begin(), ranks.end())*((long long)cars*cars);
        long long mid = -1;
        long long pos = -1; 
        while(start<=end)
        {
            mid = start + (end-start)/2;
            if(fn(mid, ranks, cars))
            {
                pos = mid;
                end = mid-1; 
            }
            else
            {
                start = mid+1; 
            }
        }
        return pos ; 

        
    }
};