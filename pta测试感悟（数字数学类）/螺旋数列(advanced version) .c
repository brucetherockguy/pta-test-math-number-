#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int c = 1, n, a[11][11] = { 0 };
    scanf("%d", &n);
    int x = 0, y = 0;
    a[x][y] = 1;
    while (n * n > c)/*结束条件*/ {
        while (y + 1 < n && !a[x][y + 1]/*这个非0的判定太妙了，一到不是零的就跳到下一个，c也不会增加*/) {
            a[x][++y] = ++c;

        }
        while (x + 1 < n && !a[x + 1][y]) {
            a[++x][y] = ++c;

        }
        while (y - 1 >= 0 && !a[x][y - 1]) {
            a[x][--y] = ++c;

        }
        while (x - 1 >= 0 && !a[x - 1][y]) {
            a[--x][y] = ++c;

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}
