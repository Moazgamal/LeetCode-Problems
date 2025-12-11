class Solution {
public:
    string entityParser(string text) {
        string str = "";
        for(int i =0; i< text.size(); )
        {
            if(text[i] == ' ')
            {
                str.push_back(' ');
                i++; continue;
            }
            if(text[i] == '&')
            {
                if(i+6 < text.size() && text.substr(i, 7) == "&frasl;")
                {
                    str+="/";
                    i=i+7;
                    continue;
                }
                else if(i+5<text.size() && text.substr(i, 6) == "&quot;")
                {
                    str+="\"";
                    i=i+6;
                    continue;
                    
                }
                else if(i+5<text.size() && text.substr(i, 6)=="&apos;")
                {
                    str+="\'";
                    i=i+6;
                    continue;
                }
                else if(i+4 < text.size() && text.substr(i, 5) == "&amp;")
                {
                    str+="&";
                    i=i+5;
                    continue;
                }
                else if(i+3 < text.size() && text.substr(i, 4) == "&gt;")
                {
                    str+=">";
                    i=i+4;
                    continue;
                }
                else if(i+3 < text.size() && text.substr(i, 4) == "&lt;")
                {
                    str+="<";
                    i=i+4;
                    continue;
                }
                else
                {
                    str.push_back('&');
                    i++;
                }
            }
            else
            {
                str.push_back(text[i]);
                i++;
            }
        }return str; 
        
    }
};