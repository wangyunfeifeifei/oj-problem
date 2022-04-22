#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    char name[20];
    int age;
    int score;
};

int main() {
    int n;
    scanf("%d", &n);
    Student stu[n];
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", stu[i].name, &stu[i].age, &stu[i].score);
        stu[i].score = min(600, (int) (stu[i].score * 1.2));
        stu[i].age++;
        printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
    }
    return 0;
}
