class Solution {
public:
    string reformat(string s) {
        int cnt1 = 0; int cnt2 = 0;
        string v1 = "";string v2 = "";
        for(int i =0; i< s.size(); i++)
        {
            if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3'
            || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7'
            || s[i] == '8' || s[i] == '9')
            {
                cnt1++; v1.push_back(s[i]);
            }
            else
            {
                cnt2++; v2.push_back(s[i]);
            }
        }
        if(abs(cnt1-cnt2) >1)
            return "";
        string ans ="";
        if(v1.size() == v2.size())
        {
            for(int i = 0; i< v1.size(); i++)
            {
                ans.push_back(v1[i]);
                ans.push_back(v2[i]);
            }
        }else if(v1.size() > v2.size())
        {
            for(int i = 0; i< v1.size(); i++)
            {
                ans.push_back(v1[i]);
                if(i< v2.size())
                    ans.push_back(v2[i]);
            }
        }else if(v2.size() > v1.size())
        {
            for(int i = 0; i< v2.size(); i++)
            {
                ans.push_back(v2[i]);
                if(i< v1.size())
                    ans.push_back(v1[i]);
            }
        }return ans; 

        
    }
};