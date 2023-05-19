#include <stdio.h>

/* 判斷是否為閏年 */
int LeapYear(int year)
{
    if(year % 4 != 0){
        return 0;
    }
    else if(year % 100 != 0){
        return 1;
    }
    else if(year % 400 != 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    int T; /* 測試資料的組數 */
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        int d1, m1, y1; /* 現在日期 */
        int d2, m2, y2; /* 出生日期 */
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);

        /* 如果出生日期比現在日期晚，表示一個不可能的年紀，例如還沒出生 */
        if(y2 > y1 || (y2 == y1 && (m2 > m1 || (m2 == m1 && d2 > d1)))){
            printf("Case #%d: Invalid birth date\n", i);
        }
        else{
            int age = y1 - y2; /* 計算年齡 */

            /* 如果今年生日還沒到，年齡要減1 */
            if(m1 < m2 || (m1 == m2 && d1 < d2)){
                age--;
            }

            /* 如果年齡小於0或大於130，表示資料有誤 */
            if(age < 0){
                printf("Case #%d: Invalid birth date\n", i);
            }
            else if(age > 130){
                printf("Case #%d: Check birth date\n", i);
            }
            else{
                printf("Case #%d: %d\n", i, age);
            }
        }
    }

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 陳俞妏*/
