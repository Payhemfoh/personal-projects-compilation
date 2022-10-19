#include <stdio.h>

int getNum(){
    int num = 10;
    return 10 + 3;
}

int main(){
    int x;

    x = getNum();
    /*
        similar
        int num = 10;
        x = num + 3;
    */
   printf("%d",x);

    return 0;
}