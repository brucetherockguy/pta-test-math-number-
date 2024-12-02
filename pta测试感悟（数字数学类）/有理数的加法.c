#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
int main()
{
    int gcd(int a, int b);
    int n;
    scanf("%d", &n);
    int a1, b1, a2, b2;
    scanf("%d/%d", &a1, &b1);
    for (int i = 1; i < n; i++) {
        scanf("%d/%d", &a2, &b2);
        a1 = a1 * b2 + a2 * b1;
        b1 = b1 * b2;
        int x = a1;
        int y = b1;
        a1 = a1 / gcd(x, y);//本题的关键在此，即每次加法后，都将得到的分数化为最简分数，这样可以大大的节省后面的计算量，否则当数字或者数字的数目很多时，将会超出范围//
        b1 = b1 / gcd(x, y);
    }
    b1 = b1 * n;
    int x = a1;
    int y = b1;
    a1 = a1 / gcd(x, y);
    b1 = b1 / gcd(x, y);
    printf("%d", a1);
    if (b1 != 1) {
        printf("/%d", b1);
    }
    return 0;
}
int gcd(int a, int b)//欧几里得算法//
{
    int a_temp = fabs(a) < b ? fabs(a) : b;
    int b_temp = fabs(a) > b ? fabs(a) : b;
    while (a_temp != 0) {
        int temp1 = b_temp;
        b_temp = a_temp;
        a_temp = temp1 % a_temp;
    }
    return b_temp;
}

