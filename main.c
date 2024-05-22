#include <stdio.h>
#include "lr.h"

int main()
{
    int a;
    printf("Enters number of laboratory work: ");
    scanf("%i", &a);
    switch(a){
        case 1:
            laba1();
            break;
        case 2:
            laba2();
            break;
        case 3:
            laba3();
            break;
        case 4:
            laba4();
            break;
        case 42:
            laba42();
            break;
        case 5:
            laba5();
            break;
        case 52:
            laba52();
            break;
        case 6:
            laba6();
            break;
        case 7:
            laba7();
            break;
    }
    return 0;
}
