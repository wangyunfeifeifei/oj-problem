#include <cstdio>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> vec;
    while (n!=1) {
        vec.push_back(n);
        if (n%2==1) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
    }
    vec.push_back(1);
    for(int i = vec.size()-1; i >= 0; i--) {
        if (i == 0)
            printf("%d\n", vec[i]);
        else
            printf("%d ", vec[i]);
    }
    return 0;
}
