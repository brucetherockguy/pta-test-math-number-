#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int defeat[1001] = { 0 };
	int survival = n;
	int headcount = 0;
	int king;
	while (survival > 0) {
		for (int i = 1; i <= n; i++) {//以for1-n历遍来代替另一个版本中的新增计数变量，因为这里到n以后while循环又再次开启，又从1开始了，大大简化了形式。//
			if (defeat[i] == 1) {
				continue;
			}
			headcount++;
			if (headcount % 3 == 0) {
				defeat[i] == 1;
				survival--;
				king = i;
			}
		}
	}
	printf("%d", king);
	return 0;
}
//与另一个版本最大的区别是，他对于存活的判断是不存活，但是self version中是按存活会发生什么来的，所以说略显复杂。//