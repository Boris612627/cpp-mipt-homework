#include <stdio.h>
#include <string.h>

int main() {
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};

    printf("(a) Указатели:\n");
    char *p1 = (char*)a;
    char buf1[17];
    for (int i = 0; i < 16; i++) {
        buf1[i] = p1[i];
    }
    buf1[16] = '\0';
    printf("%s\n\n", buf1);

    printf("(b) union:\n");
    union {
        int i[4];
        char c[17];
    } u;
    for (int i = 0; i < 4; i++) {
        u.i[i] = a[i];
    }
    u.c[16] = '\0';
    printf("%s\n\n", u.c);

    printf("(c) memcpy:\n");
    char buf3[17];
    memcpy(buf3, a, 16);
    buf3[16] = '\0';
    printf("%s\n\n", buf3);

    return 0;
}
