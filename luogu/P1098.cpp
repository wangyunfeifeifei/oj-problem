#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool num(char c) {
    return c >= '0' && c <= '9';
}

bool alpha(char c) {
    return c >= 'a' && c <= 'z';
}

bool other(char c) {
    return !alpha(c) && !num(c);
}

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    stringstream ss;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' && i != 0 && i != s.size() - 1) {
            char prev = s[i - 1], rear = s[i + 1];
            if (rear <= prev
                || num(prev) && alpha(rear)
                || alpha(prev) && num(rear)
                || other(prev)
                || other(rear)) {
                ss << s[i];
                continue;
            }
            int k = rear - prev;
            string t;
            for (int j = 1; j < k; j++) {
                for (int x = 0; x < p2; x++) {
                    char r = prev + j;
                    if (p1 == 1) t.push_back(r);
                    else if (p1 == 2) {
                        if (alpha(r)) t.push_back(r - 'a' + 'A');
                        else t.push_back(r);
                    } else {
                        t.push_back('*');
                    }
                }
            }
            if (p3 == 2) reverse(t.begin(), t.end());
            ss << t;
        } else {
            ss << s[i];
        }
    }
    cout << ss.str() << endl;
    return 0;
}
