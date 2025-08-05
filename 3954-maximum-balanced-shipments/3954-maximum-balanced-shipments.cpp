class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {

        int res = 0;
    for (int i = 1; i < weight.size(); ++i)
        if (weight[i - 1] > weight[i]) {
            ++res;
            ++i;
        }
    return res;
        
    }
};