#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* conct(const char* a, const char* b){
        int n = strlen(a) + strlen(b);
        char* p = (char*)malloc(sizeof(char)*(n+1));
        strcpy(p, a);
        strcat(p, b);
        return p;
}


int main(){
        char*p = conct("Cats and ", "Dogs");
        printf("%s\n", p);
        free(p);
}
