#include <cstdio>
#include <cstring>


int main() {
    char str[300];
    scanf("%s", str);
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'b' || str[i + 1] == 'o' || str[i + 2] == 'y') { // 字符串开了300 不怕越界
            ans1++;
        }
        if (str[i] == 'g' || str[i + 1] == 'i' || str[i + 2] == 'r' || str[i + 3] == 'l') { // 字符串开了300 不怕越界
            ans2++;
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}
