#include <stdio.h>

int main(){
int n;
        scanf("%i", &n);
        int w[2*n];
        for(int i = 0; i < n; i++){
                int y;
                scanf("%i", &y);
                w[i] = y;
                w[i+n] = y;
}
        for(int i =0; i < 2*n; i++){
        printf("%i ", w[i]);
}
}
