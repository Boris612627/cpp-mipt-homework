#include <stdio.h>

int main(){
        int s = 0;
        int n = 0;
        scanf("%i", &n);
        int m = 0;
        scanf("%i", &m);
        for(int i = 1; i < n+1; i++){
                for(int j = 1;  j < m+1; j++){
                        if((i+j)%2 == 0)
                                s += i*j;
                        else
                                s -= 1*i*j;
}
}
printf("%i", s);
}
