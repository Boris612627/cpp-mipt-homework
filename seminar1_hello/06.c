#include <stdio.h>

int main(){
        int a = 0;
        scanf("%i", &a);
        int mx = a;
        int len = 1;
printf("%i ", a);
        while(a > 1){
                if(a%2 == 0)
                a = a/2;
                else
                a = 3*a + 1;
                printf("%i ", a);
        if(a > mx)
                mx = a;
        len += 1;
}
printf("\nLength = %i, Max = %i", len, mx);


}
