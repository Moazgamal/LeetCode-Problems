class Solution {
public:
    string makeFancyString(string s) {
        string x ="";
        int j =0;
        for(int i = 0; i< s.size(); i++)
        {
            if(j-2>=0 && s[i] == x[j-1] && s[i] == x[j-2])
                continue;
            x += s[i]; j++;
        }return x;
        
    }
};