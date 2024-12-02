/*7-6 螺旋方阵
所谓“螺旋方阵”，是指对任意给定的N，将1到N×N的数字从左上角第1个格子开始，按顺时针螺旋方向顺序填入N×N的方阵里。本题要求构造这样的螺旋方阵。

输入格式：
输入在一行中给出一个正整数N（<10）。

输出格式：
输出N×N的螺旋方阵。每行N个数字，每个数字占3位。*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[10][10] = { 0 };
	int count = 0;
	for (int i = 1; i <= n / 2; i++) {
		for (int j = i - 1; j < n - i; j++) {
			a[i - 1][j] = ++count;
		}
		for (int j = i - 1; j < n - i; j++) {
			a[j][n - i] = ++count;
		}
		for (int j = i - 1; j < n - i; j++) {
			a[n - i][n - j - 1] = ++count;
		}
		for (int j = i - 1; j < n - i; j++) {
			a[n - j - 1][i - 1] = ++count;
		}
	}
	if (n % 2 == 1) {
		a[n / 2][n / 2] = n * n;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}