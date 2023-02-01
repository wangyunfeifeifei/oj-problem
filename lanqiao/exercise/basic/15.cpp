#include <iostream>
#include <cstring>

bool case3(char *a, char *b) {
    int len = strlen(a);
    if(strlen(b) != len) {
        return false;
    }
    for(int i = 0; i < len; i++) {
        if(tolower(a[i]) != tolower(b[i])) {
            return false;
        }
    }
    return true;
}

int main() {

    char s1[20], s2[20];
    scanf("%s%s", s1, s2);
    if(strlen(s1) != strlen(s2)) {
        printf("1\n");
    } else if(strcmp(s1, s2) == 0) {
        printf("2\n");
    } else if(case3(s1, s2)) {
        printf("3\n");
    } else {
        printf("4\n");
    }

    return 0;
}
