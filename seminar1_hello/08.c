#include <stdio.h>

int main(){
        int a;
        int b;
        int c;
        scanf("%i\n%i\n%i", &a, &b, &c);
        if(a%c != 0)
                a = (a-a%c) + c;
        for(int i = a; i <= b; i += c){
                printf("%i ", i);
}

}
