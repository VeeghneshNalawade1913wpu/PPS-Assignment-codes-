#include <stdio.h>
#include <time.h>

int isLeapYear(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void printMonth(const char *name, int year, int days, int startDay)
{
    printf("\n%s %d\n", name, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < startDay; i++) {
        printf("    ");
    }

    for (int day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((startDay + day) % 7 == 0 || day == days) {
            putchar('\n');
        } else {
            putchar(' ');
        }
    }
}

int main(void)
{
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;

    printf("Enter the year: ");
    fflush(stdout);
    if (scanf("%d", &year) != 1 || year < 1) {
        fprintf(stderr, "Please enter a positive year.\n");
        return 1;
    }

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    /* Gregorian weekdays repeat every 400 years. */
    struct tm firstDay = {0};
    firstDay.tm_year = 100 + year % 400;
    firstDay.tm_mday = 1;
    firstDay.tm_hour = 12;
    firstDay.tm_isdst = -1;
    if (mktime(&firstDay) == (time_t)-1) {
        fprintf(stderr, "Could not determine the first weekday.\n");
        return 1;
    }

    int startDay = firstDay.tm_wday;
    for (int month = 0; month < 12; month++) {
        printMonth(months[month], year, daysInMonth[month], startDay);
        startDay = (startDay + daysInMonth[month]) % 7;
    }

    return 0;
}
