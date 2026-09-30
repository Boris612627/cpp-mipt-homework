#include <stdio.h>

int main(){
        char a[100];
        char b[100];
        scanf("%s %s", a, b);
        int sig1 = 1;
        int sig2 = 1;
        for(int i = 0; i < 100; i++){
                if(sig1 != 0 && a[i] == 0)
                        sig1 = 0;
                if(sig1)
                        printf("%c", a[i]);
                if(sig2 != 0 && b[i] == 0)
                        sig2 = 0;
                if(sig2)
                        printf("%c", b[i]);
                if(sig1 == 0 && sig2 == 0)
                        break;
}
}
