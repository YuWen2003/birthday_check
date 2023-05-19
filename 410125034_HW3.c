#include <stdio.h>

/* �P�_�O�_���|�~ */
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
    int T; /* ���ո�ƪ��ռ� */
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        int d1, m1, y1; /* �{�b��� */
        int d2, m2, y2; /* �X�ͤ�� */
        scanf("%d/%d/%d", &d1, &m1, &y1);
        scanf("%d/%d/%d", &d2, &m2, &y2);

        /* �p�G�X�ͤ����{�b����ߡA��ܤ@�Ӥ��i�઺�~���A�Ҧp�٨S�X�� */
        if(y2 > y1 || (y2 == y1 && (m2 > m1 || (m2 == m1 && d2 > d1)))){
            printf("Case #%d: Invalid birth date\n", i);
        }
        else{
            int age = y1 - y2; /* �p��~�� */

            /* �p�G���~�ͤ��٨S��A�~�֭n��1 */
            if(m1 < m2 || (m1 == m2 && d1 < d2)){
                age--;
            }

            /* �p�G�~�֤p��0�Τj��130�A��ܸ�Ʀ��~ */
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

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ���\ʹ*/
