#include <stdio.h>

int len(const char s[]) {
    int i = 0;

    while (s[i]) {
        i++;
    }

    return i;
}
int str_char(const char s[], char c) {
    int i, p = -1;

    for (i = 0; i < len(s); i++) {
        if (s[i] == c) {
            p = i;
            break;
        }

    }

    return p;
}
int main() {
    char s[10] = "asdasd";
    char c = 's';
    printf("%d\n", str_char(s, c));
    return 0;
}