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
		for (int i = 1; i <= n; i++) {//��for1-n������������һ���汾�е�����������������Ϊ���ﵽn�Ժ�whileѭ�����ٴο������ִ�1��ʼ�ˣ���������ʽ��//
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
//����һ���汾���������ǣ������ڴ����ж��ǲ�������self version���ǰ����ᷢ��ʲô���ģ�����˵���Ը��ӡ�//