#include <stdio.h>

int len(const char s[]) {
    int i = 0;

    while (s[i]) {
        i++;
    }

    return i;
}
void rev_string(char s[][128], int n) {
    int i, j;
    char temp;

    for (j = 0; j < n; j++) {
        for (i = 0; i < len(s[j]) / 2; i++) {
            temp = s[j][i];
            s[j][i] = s[j][len(s[j]) - i - 1];
            s[j][len(s[j]) - i - 1] = temp;

        }
    }
}
int main() {
    int n = 3;
    char s[3][128] = {"asdasd","salkdjl","qwer"};
 
     rev_string(s, n);
    printf("%s\n%s\n%s\n", s[0],s[1],s[2]);
    return 0;
}