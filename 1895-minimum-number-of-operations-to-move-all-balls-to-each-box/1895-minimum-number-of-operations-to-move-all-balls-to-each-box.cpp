class Solution {
public:
    vector<int> minOperations(string boxes) {

        vector<int> prefixSums(boxes.size(),0);
        vector<int> suffixSums(boxes.size(), 0);
        int prefix = 0; int ones = 0; 
        for(int i =0; i< boxes.size(); i++)
        {
            prefix += ones;
            prefixSums[i] = prefix;
            if(boxes[i] == '1')
                ones++;
        }
        ones = 0; int suffix = 0; 
        for(int i = boxes.size()-1; i >= 0; i--)
        {
            suffix += ones;
            suffixSums[i] = suffix;
            if(boxes[i] == '1')
                ones++;
        }
        vector<int> result(boxes.size(),0);
        for(int i = 0; i< boxes.size(); i++)
        {
            result[i] = prefixSums[i] + suffixSums[i];
        }return result;
        
    }
};