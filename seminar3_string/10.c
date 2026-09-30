#include <stdio.h>
#include <string.h>

int main(){
        int n;
        int x = 0;
        int y = 0;
        char N[10] = "North";
        char S[10] = "South";
        char W[10] = "West";
        char E[10] = "East";
        scanf("%i", &n);
        for(int i = 0; i < n; i++){
                int k;
                char str[10];
                scanf("%s %i", str, &k);
                        if(strcmp(str, N) == 0) y += k;
                        else if(strcmp(str, S) == 0) y -= k;
                        else if(strcmp(str, E) == 0) x += k;
                        else x -= k;
}
        printf("%i %i", x, y);
}
