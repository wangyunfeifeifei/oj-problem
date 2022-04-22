#include <cstdio>
#include <cstring>

int main() {
    int n;
    char pwd[51];
    scanf("%d", &n);
    scanf("%s", pwd);
    for (int i = 0; i < strlen(pwd); i++) {
        pwd[i] = (pwd[i] - 'a' + n) % 26 + 'a';
    }

    printf("%s\n", pwd);
    return 0;
}
