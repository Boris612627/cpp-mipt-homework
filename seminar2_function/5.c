#include <stdio.h>

int print_bin(int a){
        if(a <= 0) return 0;
        int b = 0;
        b = print_bin(a/2)*10 + a%2;
        return b;
}

int main(){
        int a;
        scanf("%i", &a);
        printf("%i", print_bin(a));
}


