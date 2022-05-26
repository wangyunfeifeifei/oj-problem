#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct P {
    int no; // 序号
    string name;
    string position;
    int bg;
    int level;
} p[120];

unordered_map<string, int> w;

int main() {
    w["BangZhu"] = 0;
    w["FuBangZhu"] = 1;
    w["HuFa"] = 2;
    w["ZhangLao"] = 3;
    w["TangZhu"] = 4;
    w["JingYing"] = 5;
    w["BangZhong"] = 6;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].position >> p[i].bg >> p[i].level;
        p[i].no = i;
    }
    sort(p + 3, p + n, [](P a, P b) -> bool {
        if (a.bg == b.bg) return a.no < b.no;
        else return a.bg > b.bg;
    });
    for (int i = 3; i < n; i++) {
        if (i >= 3 && i <= 4) p[i].position = "HuFa";
        else if (i > 4 && i <= 8) p[i].position = "ZhangLao";
        else if (i > 8 && i <= 15) p[i].position = "TangZhu";
        else if (i > 15 && i <= 40) p[i].position = "JingYing";
        else p[i].position = "BangZhong";
    }
    sort(p, p + n, [](P a, P b) -> bool {
        if (a.position == b.position && a.level == b.level) return a.no < b.no;
        else if (a.position == b.position) return a.level > b.level;
        else return w[a.position] < w[b.position];
    });
    for (int i = 0; i < n; i++) {
        cout << p[i].name << " " << p[i].position << " " << p[i].level << endl;
    }
    return 0;
}
