class Solution {
public:
    int maxDiff(int num) {

        string str = to_string(num);
        string str1 = str;
        string str2 = str;
        char c1 = ' ';
        char c2 = ' ';
        for(int i = 0; i< str.size(); i++)
        {
            if(i == 0)
            {
                while(i< str.size() && str[i] == '9')
                {
                    i++;
                }
                if(i< str.size())
                {
                    c1 = str[i];
                    str1[i] = '9';
                }
            }
            if(str[i] == c1)
            {
                str1[i] = '9';
            }
        }
        bool u = false;
        for(int i = 0; i< str.size(); i++)
        {
            if(i == 0)
            {
               if(str[0] == '1')
                    i++;
                else
                {
                    c2 = str[0];
                    str2[0] = '1';
                    continue;
                }
                while(i< str.size() && (str[i] =='0' || str[i] =='1'))
                {
                    i++;
                }
                if(i< str.size())
                {
                    c2 = str[i];
                    u= true;
                }
            }
            if(str[i] == c2 && u== false)
            {
                str2[i] = '1';
            }
            else if(str[i] == c2 && u)
            {
                str2[i] = '0';
            }
        }
        cout<<stoi(str1)<<" "<<stoi(str2)<<"\n";
        return stoi(str1)-stoi(str2);

        
    }
};