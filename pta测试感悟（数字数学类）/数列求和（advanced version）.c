#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
    int a, n;
    int num[100001] = { 0 };//�ʼ��λ�Ŀ���//
    scanf("%d %d", &a, &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) {//���ǿ�������ֻ��һ��ѭ����������һ����Ҳֻ��һ��ѭ������˵�����Ż��������ط���//
        int temp = num[n - i + 1] + a * (n - i + 1);
        num[n - i + 1] = temp % 10;//���ȣ���һ�α��һλ�����ֽ�����������ġ�Ӱ�조����������ʹ����������Ƕ������ѭ��//
        num[n - i] = num[n - i] + temp / 10;//���ڽ�λ������Ż�����������û��һ�ν���λȫ���õ�ÿһλ�ϣ�����ͨ����10����ʱ��������һλ�����ּ���һ��ѭ��//
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