#define _CRT_SECURE_NO_WARNINGS 1
/*给定不超过6的正整数A，考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数。

输入格式：
输入在一行中给出A。

输出格式：
输出满足条件的的3位数，要求从小到大，每行6个整数。整数间以空格分隔，但行末不能有多余空格。*/
#include<stdio.h>
int main()
{
    int a, b;
    int i, j, k;
    int flag;
    flag = 0;

    scanf("%d", &a);
    b = a + 4;
    for (i = a; i < b; i++)//另一种类型的贪心算法？？？从最小值出发，剔除含有重复数字的即可，妙哉！//
    {
        for (j = a; j < b; j++)
        {
            for (k = a; k < b; k++)//从k开始改变，在变j，再变i，刚好是递增的顺序！！//
            {
                if (i != j && k != i && k != j)
                {
                    flag++;
                    if (flag % 6 != 0)
                    {
                        printf("%d ", i * 100 + j * 10 + k);
                    }
                    else
                    {
                        printf("%d\n", i * 100 + j * 10 + k);
                    }
                }

            }
        }
    }

    return 0;
}