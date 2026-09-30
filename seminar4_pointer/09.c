#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used){
        int flag[26] = {0};
        while(*str != 0){
                if(isalpha(*str)){
                        int ind = tolower(*str) - 'a';
                        flag[ind] = 1;
}
                str += 1;
}
        for(int i = 0; i < 26; i++){
                if(flag[i] == 1){
                        *used = 'a' + i;
                        used += 1;
}
}
        *used = 0;
}

int main() {
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);

    return 0;
}

