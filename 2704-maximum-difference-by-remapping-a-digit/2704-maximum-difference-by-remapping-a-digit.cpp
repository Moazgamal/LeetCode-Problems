class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string str2 = str;
        char idx1 = str[0];
        int i = 0; 
        while(i< str.size())
        {
            if(str[i] == idx1)
            {
                str[i] = '0';
            }
            i++;
        }
        i=0;
        while(i< str2.size())
        {
            if(str2[i] != '9')
                break;
            i++;
        }
        if(i== str2.size())
        {
            return stoi(str2)-stoi(str);
        }
        char idx2 = str2[i];
        while(i<str2.size())
        {
            if(str2[i] == idx2)
            {
                str2[i] = '9';
            }
            i++;
        }
        return stoi(str2)-stoi(str);
    }
};