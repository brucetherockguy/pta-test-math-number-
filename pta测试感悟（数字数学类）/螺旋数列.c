/*7-6 ��������
��ν���������󡱣���ָ�����������N����1��N��N�����ִ����Ͻǵ�1�����ӿ�ʼ����˳ʱ����������˳������N��N�ķ��������Ҫ������������������

�����ʽ��
������һ���и���һ��������N��<10����

�����ʽ��
���N��N����������ÿ��N�����֣�ÿ������ռ3λ��*/
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