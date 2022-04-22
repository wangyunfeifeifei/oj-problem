#include <cstdio>
#include <cstring>

int cnt[26] = {0};

int main() {
    char str[101];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        cnt[str[i] - 'a']++;
    }
    int max = cnt[0], min = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        if (min == 0) min = cnt[i];
        else if (cnt[i] < min) min = cnt[i];
        if (cnt[i] > max) max = cnt[i];
    }
    int diff = max - min;
    bool flag = true;
    for (int i = 2; i * i <= diff; i++) {
        if (diff % i == 0) {
            flag = false;
            break;
        }
    }
    if (diff < 2) flag = false;
    if (flag) {
        printf("Lucky Word\n");
        printf("%d\n", diff);
    } else {
        printf("No Answer\n");
        printf("0\n");
    }
    return 0;
}
