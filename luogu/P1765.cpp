#include <cstdio>
#include <cstring>

int main() {
    int cnt[27] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
                   3, 1, 2, 3, 1, 2, 3, 4, 1, 2,
                   3, 1, 2, 3, 4, 1};
    char str[205];
    int ans = 0;
    fgets(str, 205, stdin);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') ans += cnt[26];
        else if (str[i] >= 'a' && str[i] <= 'z') ans += cnt[str[i] - 'a'];
    }
    printf("%d\n", ans);
    return 0;
}
