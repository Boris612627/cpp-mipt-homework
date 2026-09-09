#include <stdio.h>

int main(){
        int n, m;
        scanf("%i\n%i", &n, &m);
        int w[m];
        for(int i = 0; i < m; i++){w[i] = 0;}
        for(int i =0; i < m*n; i++){
                int y;
                scanf("%i", &y);
                w[i%m] += y;
}
        for(int i =0; i < m; i++){
                printf("%i ", w[i]);
}
}
