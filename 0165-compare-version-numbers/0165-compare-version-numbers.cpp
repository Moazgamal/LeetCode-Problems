class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i = 0; int j = 0; 
        while(i< version1.size() && j < version2.size())
        {
            string str1 = ""; string str2 = ""; 
            int num1 = 0; int num2 = 0; 
            while(i< version1.size() && version1[i] != '.')
            {
                str1.push_back(version1[i]); i++;
            }
            while(j< version2.size() && version2[j] != '.')
            {
                str2.push_back(version2[j]); j++;
            }
            num1 = stoi(str1); num2 = stoi(str2);
            if(num1< num2)
                return -1; 
            if(num1 > num2)
                return 1; 
            
            i++; j++;
        }
        if(i>= version1.size() && j >= version2.size())
            return 0; 
        if(i >= version1.size())
        {
            while(j <version2.size())
            {
                while(j< version2.size() && version2[j] != '.')
                {
                    if(version2[j] != '0')
                    {
                        return -1;
                    }
                    j++;
                }
                j++;
            }
            return 0; 
        }
        if(j >= version2.size())
        {
            while(i <version1.size())
            {
                while(i< version1.size() && version1[i] != '.')
                {
                    if(version1[i] != '0')
                    {
                        return 1;
                    }
                    i++;
                }
                i++;
            }
            return 0; 
        }
        return 0; 
        
    }
};