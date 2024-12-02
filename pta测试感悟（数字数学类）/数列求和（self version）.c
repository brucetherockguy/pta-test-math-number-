#define _CRT_SECURE_NO_WARNINGS 1
/*给定某数字A（1<=A<=9）以及非负整数N（0<=N<=100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。

输入格式：
输入数字A与非负整数N。

输出格式：
输出其N项数列之和S的值。*/
#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    int n;
    scanf("%d %d", &a, &n);
    int num[100001] = { 0 };
    if (n == 0) {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            num[j] = num[j] + a;
            int director = j;
            while (num[director] >= 10) {
                num[director] = num[director] - 10;
                num[director - 1] = num[director - 1] + 1;//本版本最大的问题出现在这里，我们看到这里首先嵌套了两层循环，而且内层循环中有两个循环，这样是很容易超时的，所以解决时间问题便可以通过减少循环，优化递推实现//
                director = director - 1;
            }
        }
    }
    if (num[0] == 0) {
        for (int i = 1; i <= n; i++) {
            printf("%d", num[i]);
        }
    }
    else {
        for (int i = 0; i <= n; i++) {
            printf("%d", num[i]);
        }
    }
    return 0;
}
//本题的n达到了10000，粗略估计位数有10000左右，这是计算机难以储存的数据，面对这样的数据输出，我们很常用的一种方法是使用数组，将每一位依次输出，这样可以避免超出范围的问题，但是这样又可能引出超时的问题，本版本在n很大时便会出现这样的问题//