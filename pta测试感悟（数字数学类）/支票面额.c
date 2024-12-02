/*一个采购员去银行兑换一张y元f分的支票，结果出纳员错给了f元y分。采购员用去了n分之后才发觉有错，于是清点了余额尚有2y元2f分，问该支票面额是多少？

输入格式：
输入在一行中给出小于100的正整数n。

输出格式：
在一行中按格式y.f输出该支票的原始面额。如果无解，则输出No Solution。*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{//不定方程 嵌入n层for循环历遍n个未知量的值//
    int n;
    scanf("%d", &n);
    int f, y;
    for (f = 0; f <= 99; f++) {
        for (y = 0/*再次内层循环时会重置初始条件*/; y <= 99; y++) {
            if (98 * f == 199 * y + n) {
                printf("%d.%d", y, f);
                return 0;//满足条件直接结束（相当于跳出整个循环），不满足条件则继续//
            }
    }
}

if (98 * f != 199 * y + n) {
    printf("No Solution");
}

return 0;
}