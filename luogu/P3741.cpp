#include <cstdio>
#include <cstring>

int main() {
    int n;
    char str[101];
    scanf("%d%s", &n, str);
    char *pos = str;
    int ans = 0;
    do {
        pos = strstr(pos, "VK");
        if (pos != NULL) {
            pos[0] = pos[1] = 'X';
            ans++;
        }
    } while (pos != NULL);
    char *p1 = strstr(str, "VV");
    char *p2 = strstr(str, "KK");
    if(p1 || p2) ans++;
    printf("%d\n", ans);
    return 0;
}
