#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string dots;
    string s;
    bool first = true;
    while (cin >> s) {
        dots += s;
        if (first) {
            printf("%d", s.length());
            first = false;
        }
    }

    vector<int> ans;
    int cur = 0;
    int cnt = 0;
    for (char ch: dots) {
        if (ch - '0' == cur) {
            cnt++;
        } else {
            printf(" %d", cnt);
            cur = !cur;
            cnt = 1;
        }
    }
    printf(" %d\n", cnt);

    return 0;
}
