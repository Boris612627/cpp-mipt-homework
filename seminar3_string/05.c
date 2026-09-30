#include <stdio.h>

char to_int(char a){
        return a - 48;
}

int main(){
        char s[100];
        scanf("%s", s);
        int b = 0;
        for(int i = 0; i < 100; i++){
                if(s[i] == 0)
                        break;
                b += to_int(s[i]);
}
        printf("%i", b);
}
