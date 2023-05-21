#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int is_valid_date(Date date) {      //宣告有效的日期結構(年、月、天、閏月)
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (date.year < 1 || date.year > 9999) return 0;

    if (date.month < 1 || date.month > 12) return 0;

    if (date.month == 2){    //閏月特別處理
        if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
            if (date.day < 1 || date.day > 29) return 0;
        }
        else {
            if (date.day < 1 || date.day > 28) return 0;
        }
    }
    else {
        if (date.day < 1 || date.day > days_in_month[date.month - 1]) return 0;
    }

    return 1;
}

int calculate_age(Date current_date, Date birth_date) {  //判斷日期是否有輸入錯誤
    if (birth_date.year > current_date.year ||
        (birth_date.year == current_date.year && birth_date.month > current_date.month) ||
        (birth_date.year == current_date.year && birth_date.month == current_date.month && birth_date.day > current_date.day)) {
        return -1;
    }

    int age = current_date.year - birth_date.year;
    if (current_date.month < birth_date.month ||
        (current_date.month == birth_date.month && current_date.day < birth_date.day)) {
        age--;
    }

    if (age > 130) {
        return -2;
    }

    return age;
}

int main() {
    int T;      //存放測試資料的組數
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {      //依次處理每一組測試資料
        printf("Case #%d:\n", i);       //輸出目前的測試資料編號

        char current_date_str[11], birth_date_str[11];
        scanf("%s", current_date_str);
        scanf("%s", birth_date_str);


/*檢查目前日期和出生日期是否符合日期格式（使用strcmp函數比較字串），如果格式不正確則輸出"Invalid date format"，並使用continue語句跳到下一次循環。*/
        if (strcmp(current_date_str, "") == 0 || strcmp(birth_date_str, "") == 0) {
            printf("Invalid date format\n");
            continue;
        }

        char* token;
        int day, month, year;

        token = strtok(current_date_str, "/");  //使用strtok函數將日期字符串拆分成日、月、年三個部分
        day = atoi(token);                      //使用atoi函數將字串轉換成整數
        token = strtok(NULL, "/");
        month = atoi(token);
        token = strtok(NULL, "/");
        year = atoi(token);
        Date current_date = {day, month, year}; //將日、月、年存入名為current_date和birth_date的Date結構體中，用來表示目前日期和出生日期。

        token = strtok(birth_date_str, "/");
        day = atoi(token);
        token = strtok(NULL, "/");
        month = atoi(token);
        token = strtok(NULL, "/");
        year = atoi(token);
        Date birth_date = {day, month, year};

        if (!is_valid_date(current_date) || !is_valid_date(birth_date)) {  //檢查current_date和birth_date是否為合法的日期
            printf("Invalid date format\n");
            continue;
        }

        int age = calculate_age(current_date, birth_date);
        if (age == -1) {
            printf("Invalid birth date\n");
        }
        else if (age == -2) {
            printf("Check birth date\n");
        }
        else {
            printf("%d\n", age);
        }
    }

    return 0;
}
