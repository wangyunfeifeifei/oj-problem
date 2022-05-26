#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    int no, lang, math, eng, total;
};

Student Stu[305];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &Stu[i].lang, &Stu[i].math, &Stu[i].eng);
        Stu[i].total = Stu[i].lang + Stu[i].math + Stu[i].eng;
        Stu[i].no = i + 1;
    }

    sort(Stu, Stu + n, [](Student a, Student b) -> bool {
        if (a.total == b.total && a.lang == b.lang) return a.no < b.no;
        else if (a.total == b.total) return a.lang > b.lang;
        else return a.total > b.total;
    });

    for (int i = 0; i < min(5, n); i++) {
        printf("%d %d\n", Stu[i].no, Stu[i].total);
    }

    return 0;
}
