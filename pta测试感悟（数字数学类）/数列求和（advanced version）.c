#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
    int a, n;
    int num[100001] = { 0 };//最开始进位的考虑//
    scanf("%d %d", &a, &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {//我们看到这里只有一层循环，而且这一层中也只有一个循环，这说明他优化了两个地方。//
        int temp = num[n - i + 1] + a * (n - i + 1);
        num[n - i + 1] = temp % 10;//首先，他一次便把一位的数字解决，并把他的”影响“表达出来，这使得我们无需嵌套两层循环//
        num[n - i] = num[n - i] + temp / 10;//关于进位问题的优化，此种做法没有一次将进位全部拿到每一位上，而是通过除10，暂时储存在上一位，这又简化了一个循环//
    }
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (num[i] == 0 && start == 0) {
            continue;
        }
        start = 1;
        printf("%d", num[i]);
    }
    return 0;
}