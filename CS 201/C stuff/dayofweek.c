//submitted by Paul James Natcher
#include <stdio.h>

int is_leap_year(int year){
    if ((year % 100 == 0) && (year % 400 == 0)) {
        return 1;
    }
    else if ((year % 100 != 0) && (year % 4 == 0)) {
        return 1;
    }
    return 0;
}
int get_century_value(int year){
    int c, r, y;
    c = year / 100;
    r = c % 4;
    y = 3 - r;
    y *= 2;
    return y;
}
int get_year_value(int year){
    int y, x;
    y = year % 100;
    x = y / 4;
    y += x;
    return y;
}
int get_month_value(int month, int year){
    int leapYearVals[12] = {6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int noleapYearVals[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    if (is_leap_year(year) == 1) {
        return leapYearVals[month - 1];
    }
    else {
        return noleapYearVals[month - 1];
    }
}
int days_of_week_number(int day, int month, int year){
    int u, v, w, sum, r;
    u = get_century_value(year);
    v = get_year_value(year);
    w = get_month_value(month, year);
    sum = u + v + w + day;
    r = sum % 7;
    return r;
}
char *day_of_week(int day, int month, int year){
    int num;
    char days[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    num = days_of_week_number(day, month, year);
    return days[num];
}

int main(void) {
    int day, month, year, weekday;

    printf("Enter the day (as a number:\n");
    scanf("%d", &day);
    printf("Enter the month (as a number:\n");
    scanf("%d", &month);
    printf("Enter the year (as a 4 digit number:\n");
    scanf("%d", &year);

    printf("%d-%d-%d is a %s\n", year, month, day, day_of_week(day, month, year));

    return 0;
}