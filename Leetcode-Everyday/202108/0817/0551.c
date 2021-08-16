#include<stdbool.h>
#include<stddef.h>
bool checkRecord(char * s){
    int a_num = 0, l_num = 0;
    while(NULL != *s)
    {
        if ('L' == *s)
        {
            l_num ++;
            if (3 == l_num)
            {
                return false;
            }
        }else{
            l_num = 0;
            if ('A' == *s)
            {
                a_num ++;
            }
        }
        s ++;
    }
    return a_num < 2;
}