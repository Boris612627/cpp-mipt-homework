#include <stdio.h>
#include <string.h>

int main(){
        char a[100];
        scanf("%s", a);
        int n = strlen(a);
        int sig = 1;
        for(int i = 0; i < n; i++){
                if(a[i] != a[n-i-1])
                        sig = 0;
                        break;
}
        if(sig)
                printf("Yes");
        else
                printf("No");
}
