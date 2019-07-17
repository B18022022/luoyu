#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void null_string(char s[]) {
    s[0] = '\0';
}
int main() {
    char s[20] = "ABCDEF";
    char m[20] ;
    null_string(s);
    strcpy(m,s);
    printf("\"%s\"",m );
    return 0;
}

