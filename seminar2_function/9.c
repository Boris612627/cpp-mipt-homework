#include <stdio.h>

void bob(int n);

void alice(int n){
        n = n*3 + 1;
        printf("%i\n", n);
        bob(n);
}

void bob(int n){
        if(n==1) return;
        if(n%2 == 1){
                alice(n);
                return;
}
        n = n/2;
        printf("%i\n", n);
        bob(n);
}
int main(){
        int n;
        scanf("%i", &n);
        alice(n);
}
