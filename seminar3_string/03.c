#include <stdio.h>
#include <ctype.h>

int main(){
        char a;
        scanf("%c", &a);
        if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
                printf("Letter");
        else if(a >= 48 && a <= 57)
                printf("Digit");
        else
                printf("Other");


        if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
                printf("Letter");
        else if(a >= '0' && a <= '9')
                printf("Digit");
        else
                printf("Other");


        if(isalpha(a))
                printf("Letter");
        else if(isdigit(a))
                printf("Digit");
        else
                printf("Other");
}
