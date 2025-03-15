class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        for(int i = 0; i< digits.size(); i++)
            {
                int s = 0; 
                if(digits[i]==0)
                    continue;
                s+= digits[i]*100;
                for(int j = 0; j< digits.size(); j++)
                    {
                        if(j==i)
                            continue;
                        s+= digits[j]*10;
                        for(int k = 0; k < digits.size(); k++)
                            {
                                if(k==i || k==j)
                                    continue;
                                s+=digits[k];
                                if(s%2==0)
                                    st.insert(s);
                                s-=digits[k];
                            }
                        s-=digits[j]*10;
                    }
            }
        return st.size(); 
        
    }
};