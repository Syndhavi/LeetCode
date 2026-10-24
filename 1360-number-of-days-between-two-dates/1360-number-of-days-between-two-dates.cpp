
class Solution {
public:
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int countDays(string s) {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(s.substr(0, 4));
        int month = stoi(s.substr(5, 2));
        int day = stoi(s.substr(8, 2));

        int totalDays = day;
        for (int y = 1971; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            if (m == 2 && isLeapYear(year)) {
                totalDays += 29;
            } else {
                totalDays += daysInMonth[m - 1];
            }
        }
        return totalDays;
    }

    int daysBetweenDates(string date1, string date2) {
        return abs(countDays(date1) - countDays(date2));
    }
};
