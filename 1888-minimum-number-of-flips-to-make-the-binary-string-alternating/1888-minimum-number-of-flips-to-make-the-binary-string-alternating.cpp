class Solution {
public:
    int minFlips(string s) {
        int k = s.size();
        s = s + s;

        int left = 0, ch1 = 0, ch2 = 0, result = 1e9;

        for(int right = 0; right < s.size(); right++){

            char expected1 = (right % 2) ? '1' : '0';
            char expected2 = (right % 2) ? '0' : '1';

            if(s[right] != expected1) ch1++;
            if(s[right] != expected2) ch2++;

            if(right - left + 1 > k){

                char leftExp1 = (left % 2) ? '1' : '0';
                char leftExp2 = (left % 2) ? '0' : '1';

                if(s[left] != leftExp1) ch1--;
                if(s[left] != leftExp2) ch2--;

                left++;
            }

            if(right - left + 1 == k){
                result = min(result , min(ch1 , ch2));
            }
        }

        return result;
    }
};