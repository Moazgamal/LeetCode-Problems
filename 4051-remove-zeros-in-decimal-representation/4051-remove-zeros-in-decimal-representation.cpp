class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0; 
        string str = to_string(n); string str2 = "";
        for(int i =0; i< str.size(); i++)
            {
                if(str[i] == '0')
                    continue;
                str2.push_back(str[i]);
            }
        return stoll(str2);
        
    }
};