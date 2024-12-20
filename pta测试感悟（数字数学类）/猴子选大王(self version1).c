/*7-28 猴子选大王
一群猴子要选新猴王。新猴王的选择方法是：让N只候选猴子围成一圈，从某位置起顺序编号为1~N号。从第1号开始报数，每轮从1报到3，凡报到3的猴子即退出圈子，接着又从紧邻的下一只猴子开始同样的报数。如此不断循环，最后剩下的一只猴子就选为猴王。请问是原来第几号猴子当选猴王？

输入格式：
输入在一行中给一个正整数N（≤1000）。
在一行中输出当选猴王的编号。*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int defeat[1001] = { 0 };//去掉使用defeat[0]的麻烦//
    int survival = n;//判定条件就是所有猴子都被踢出，那么最后的那个count便象征着最后一个猴子的编号//
    int count = 0;
    int choose = 0;
    if (n == 1) {//特殊元素，因为在模意义下模1只会产生0//
        printf("1");
        return 0;
    }
    while (survival > 0) {
        count++;
        if (defeat[count % n] == 0) {//意味着存活//
            choose++;
            if (choose % 3 == 0) {//这一个必须放在第一个if之内，因为存活猴子的"choose"线程才能够被使用，循环到非存活猴子的choose其实是上一只存活猴子的choose//
                defeat[count % n] = 1;
                survival--;
            }
        }
    }
    printf("%d", count % n);
    return 0;
}
/*类似双线程？？？本题中一个猴子其实对应了两个量，一个量是他在对列中的编号，一个是他的报数，但是这两个都涉及更新，很麻烦。所以说我们去寻找相关联的量，我们假设每一次猴子都报数，那么这个数字模n就是他的队内编号，但是
我们清楚，当猴子"踢”出去后就不会再实际报数了，但是只要报的是三的倍数，猴子就会被踢出，那么我们只需这两个线程同步进行，便可以得到最后的答案*/