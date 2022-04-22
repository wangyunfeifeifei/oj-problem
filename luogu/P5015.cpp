#include <cstdio>
#include <cstring>


int main() {
    char str[10];
    fgets(str, 10, stdin);
    int ans = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') ans++;
        else if (str[i] >= 'a' && str[i] <= 'z') ans++;
        else if (str[i] >= 'A' && str[i] <= 'Z') ans++;
    }
    printf("%d\n", ans);
    return 0;
}
