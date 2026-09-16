
#include <stdio.h>

void print_even(int a, int b){
        for(int i = (a + (a%2)); i <= b; i += 2){
                printf("%i\n", i);
}
}

int main(){
        int a;
        int b;
        scanf("%i\n%i", &a, &b);
        print_even(a, b);
}
