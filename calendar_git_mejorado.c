#include <stdio.h>
#include <math.h>

char months[13][3] = {" ", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

char weekdays[8][3] = {"", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int days_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//functions
int isLeapYear(int year);
int firstWeekDays(int month, int year);
int shiftedMonth(int month);
void printWeekdays(int num);
void printCalendar(int month, int year, int numDaysMonth, int firstWeekDay);

int main(){

    int year;
    int month;
    int numDaysMonth;
    puts("Enter the month and year: ");
    scanf("%d%*c %d%*c", &month, &year);

    if(isLeapYear(year)) days_month[2] += 1;
    numDaysMonth = days_month[month];
    //printf("%d", numDaysMonth);
    int firstWeekDay;
    firstWeekDay = firstWeekDays(month, year);
    //printf("%d", firstWeekDay);

    for(int i = 0; i < 51; i++) printf("=");
    printf("\n");
    printCalendar(month, year, numDaysMonth, firstWeekDay);
    for(int i = 0; i < 51; i++) printf("=");
    printf("\n");
    return 0;
}

int isLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0 && year) || (year % 400 == 0)) return 1;
    return 0;
}

int shiftedMonth(int month){
    if(month == 1 || month == 2) return month + 10;
    else return month -2;
}

int firstWeekDays(int month, int year){
    if(month == 1 || month == 2) year = year - 1;
    int firstDay;
    int y = year % 100;
    int c = year / 100;
    int aux;
    int shiftedMonth(int month);
    aux = (1 + floor(2.6 * (shiftedMonth(month)) - 0.2) + y + floor(0.25 * y) + floor(0.25 * c) - (2 * c));
    firstDay = aux % 7;
    if(firstDay < 0) return firstDay + 7;
    return firstDay + 1;
}

void printWeekdays(int num){
    switch (num)
    {
    case 1:
        printf("%-8s", "SUN");
        break;
    case 2:
        printf("%-8s", "MON");
        break;
    case 3:
        printf("%-8s", "TUE");
        break;
    case 4:
        printf("%-8s", "WED");
        break;
    case 5:
        printf("%-8s", "THU");
        break;
    case 6:
        printf("%-8s", "FRI");
        break;
    case 7:
        printf("%3s", "SAT");
        break;
    }
}

void printCalendar(int month, int year, int numDaysMonth, int firstWeekDay){
    int i;
    printf("                    ");
    for(i = 0; i < 3; i++){
        printf("%c", months[month][i]);
    }
    printf("/%d\n", year);
    printf("\n");
    for(i = 1; i <= 7; i++){
        printWeekdays(i);
    }
    printf("\n");
    int aux = 0;
    int aux2 = 1;
    for(i = 0; i < 7; i++){
        if(aux < firstWeekDay - 1){
            printf("%-8s", "--");
            aux += 1;
        }
    }
    for(int j = 0; j <= numDaysMonth + 1; j++){
        
        if(aux2 < 10){
            printf("0%-7d", aux2);
            aux += 1;
            aux2 += 1;
        }
        else if(aux2 <= numDaysMonth){
            printf("%-8d", aux2);
            aux += 1;
            aux2 += 1;
        }
        if(j == numDaysMonth + 1){
            while(aux % 7 != 0){
                printf("%-8s", "--");
                aux += 1;
                if(aux % 7 == 0) printf("\n");
            }
            break;
        }
        if(aux % 7 == 0 && aux2 != numDaysMonth){
            printf("\n");
        }
        
    }
}