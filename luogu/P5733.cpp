#include <cstdio>
#include <cstring>

char to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 'A';
    return ch;
}

int main() {
    char str[101];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = to_upper(str[i]);
    }
    printf("%s\n", str);
    return 0;
}
