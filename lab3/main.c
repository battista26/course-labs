#include <limits.h>
#include <stdio.h>

int main(void){
    char a[][2] = {"1", "2", "3", "4", "5"};
    char *p = a[0];
    char **pp = &p;
    for (char i = 0; i < 5; i++){
        printf("%d. eleman: %s\n", (i+1), *(a+i));

    }


    return 0;
}