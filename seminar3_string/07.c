#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(char* str, int k){
        int n = strlen(str);
        for(int i = 0; i < n; i++){
                if(isupper(str[i]))
                        str[i] = 'A' + (str[i] - 'A' + k) % 26;
                else if(islower(str[i]))
                        str[i] = 'a' + (str[i] - 'a' + k) % 26;
}
}
