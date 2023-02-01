#include <iostream>
using namespace std;

int main() {
    int h, m, s;
    int t;
    cin >> t;
    h = t / 3600;
    m = (t/60) % 60;
    s = t % 60;
    printf("%d:%d:%d\n", h, m, s);
    return 0;
}
