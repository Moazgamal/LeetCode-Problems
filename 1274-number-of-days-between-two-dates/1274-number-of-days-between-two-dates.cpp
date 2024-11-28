class Solution {
    bool isLeap(int &year)
    {
        if(year %100 ==0)
            if(year %400 ==0)
                return true;
            else
                return false;
        else if(year %4 ==0)
            return true;
        return false;
    }
    int daysInMonth(int &month, int &year)
    {
        if(month == 2)
            if(isLeap(year))
                return 29;
            else
                return 28;
        if(month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        return 31;
    }
    int calcDays(int &minYear, int &curYear, string &Date)
    {
        int totalDays = 0; 
        for(int y = minYear; y < curYear; y++)
        {
            if(isLeap(y))
                totalDays += 366;
            else
                totalDays += 365;
        }
        int curMonth = stoi(Date.substr(5,2));
        for(int month = 1; month < curMonth; month++)
        {
            totalDays += daysInMonth(month, curYear);
        }
        int curDays = stoi(Date.substr(8,2));
        totalDays += curDays;
        return totalDays;
    }
public:
    int daysBetweenDates(string date1, string date2) {

        int year1 = stoi(date1.substr(0,4));
        int year2 = stoi(date2.substr(0,4));
        int minYear = min(year1, year2);

        int Days1 = calcDays(minYear, year1, date1);
        int Days2 = calcDays(minYear, year2, date2);
        return abs(Days1-Days2);

        
    }
};



