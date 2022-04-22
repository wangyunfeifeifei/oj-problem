#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Student {
    char name[10];
    int lang;
    int math;
    int eng;
} stu[1001];

bool similar(Student a, Student b) {
    return abs(a.lang - b.lang) <= 5 &&
           abs(a.math - b.math) <= 5 &&
           abs(a.eng - b.eng) <= 5 &&
           abs(a.lang - b.lang + a.math - b.math + a.eng - b.eng) <= 10;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", stu[i].name, &stu[i].lang, &stu[i].math, &stu[i].eng);
    }

    vector<pair<char *, char *>> vec;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (similar(stu[i], stu[j])) {
                vec.push_back({stu[i].name, stu[j].name});
            }
        }
    }

    sort(vec.begin(), vec.end(), [](pair<char *, char *> a, pair<char *, char *> b) -> bool {
        int c = strcmp(a.first, b.first);
        if (c != 0) return c < 0;
        else return strcmp(a.second, b.second) < 0;
    });

    for (auto &p: vec) {
        printf("%s %s\n", p.first, p.second);
    }

    return 0;
}
