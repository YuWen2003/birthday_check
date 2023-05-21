#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int is_valid_date(Date date) {      //�ŧi���Ī�������c(�~�B��B�ѡB�|��)
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (date.year < 1 || date.year > 9999) return 0;

    if (date.month < 1 || date.month > 12) return 0;

    if (date.month == 2){    //�|��S�O�B�z
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

int calculate_age(Date current_date, Date birth_date) {  //�P�_����O�_����J���~
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
    int T;      //�s����ո�ƪ��ռ�
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {      //�̦��B�z�C�@�մ��ո��
        printf("Case #%d:\n", i);       //��X�ثe�����ո�ƽs��

        char current_date_str[11], birth_date_str[11];
        scanf("%s", current_date_str);
        scanf("%s", birth_date_str);


/*�ˬd�ثe����M�X�ͤ���O�_�ŦX����榡�]�ϥ�strcmp��Ƥ���r��^�A�p�G�榡�����T�h��X"Invalid date format"�A�èϥ�continue�y�y����U�@���`���C*/
        if (strcmp(current_date_str, "") == 0 || strcmp(birth_date_str, "") == 0) {
            printf("Invalid date format\n");
            continue;
        }

        char* token;
        int day, month, year;

        token = strtok(current_date_str, "/");  //�ϥ�strtok��ƱN����r�Ŧ�������B��B�~�T�ӳ���
        day = atoi(token);                      //�ϥ�atoi��ƱN�r���ഫ�����
        token = strtok(NULL, "/");
        month = atoi(token);
        token = strtok(NULL, "/");
        year = atoi(token);
        Date current_date = {day, month, year}; //�N��B��B�~�s�J�W��current_date�Mbirth_date��Date���c�餤�A�ΨӪ�ܥثe����M�X�ͤ���C

        token = strtok(birth_date_str, "/");
        day = atoi(token);
        token = strtok(NULL, "/");
        month = atoi(token);
        token = strtok(NULL, "/");
        year = atoi(token);
        Date birth_date = {day, month, year};

        if (!is_valid_date(current_date) || !is_valid_date(birth_date)) {  //�ˬdcurrent_date�Mbirth_date�O�_���X�k�����
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
