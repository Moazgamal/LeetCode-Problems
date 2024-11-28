class Solution {
    int daysInMonth(int month , int year)
    {
        if(month == 2)
            if(year %100==0)
                if(year %400 ==0)
                    return 29;
                else
                    return 28;
            else if(year %4 ==0)
                return 29;
            else
                return 28;
        if(month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        return 31;
    }
public:
    int dayOfYear(string date) {

        int months = stoi(date.substr(5,2));
        int days = stoi(date.substr(8,2));
        int result = 0; 
        int year = stoi(date.substr(0, 4));
        for(int m = 1; m < months; m++)
        {
            result += daysInMonth(m, year);
        }
        result += days;
        return result;
        
    }
};