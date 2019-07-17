#include <stdio.h>

int len(const char s[]) {
    int i = 0;

    while (s[i]) {
        i++;
    }

    return i;
}
void rev_string( char s[]) {
    int i;
    char temp;

    for (i = 0; i < len(s)/2; i++) {
       temp = s[i];
       s[i] = s[len(s)-i-1];
       s[len(s)-i-1] = temp;

    }

}
int main() {
    char s[10] = "asdasd";
    rev_string(s);
    printf("%s\n",s);
    return 0;
}