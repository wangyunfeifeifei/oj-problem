/**
 * 问题描述：
 * 给定长度为N的字符串S，要构造一个长度为N的字符串T。
 * 起初，T是一个空串，随后反复进行下列任意操作。
 *
 * - 从S的头部删除一个字符，加到T的尾部
 * - 从S的尾部删除一个字符，加到T的尾部
 * 目标是要构造字典序尽可能小的字符串T。
 *
 * 1 <= N <= 2000
 * 字符串S只包含大小英文字母
 *
 * 解决方案：不断取S的开头和结尾中较小的一个字符放到T的末尾
 *
 * 算法：
 * - 按照字典序比较S和将S反转后的S'
 * - 如果S较小，就从S的开头取出一个字符，追加到T末尾。
 * - 如果S'较小，就从S的末尾取出一个字符，追加到T末尾。
 *
 */

#include <cstdio>

using namespace std;

const int MAX_N = 2001;
int N;
char S[MAX_N + 1];

void solve() {
    int a = 0, b = N - 1;
    int outCount = 0;
    while (a <= b) {
        // 将从左起和右起的字符串进行比较
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (S[a + i] < S[b - i]) {
                left = true;
                break;
            } else if (S[a + i] > S[b - i]) {
                left = false;
                break;
            }
        }

        if (left) putchar(S[a++]);
        else putchar(S[b--]);
        ++ outCount;
        if (outCount%80==0) {
            putchar('\n');
        }
    }

    if(outCount%80 != 0)
        putchar('\n');
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        getchar();
        scanf("%c", &S[i]);
    }
    solve();
    return 0;
}
