class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result_set;
    set<int> cur_set;
    
    for (int num : arr) {
        set<int> next_set;
        next_set.insert(num);
        
        for (int x : cur_set) {
            next_set.insert(x | num);
        }
        
        cur_set = next_set;
        result_set.insert(cur_set.begin(), cur_set.end());
    }
    
    return result_set.size();
        
    }
};