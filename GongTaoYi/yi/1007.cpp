�ҵ�һ�������ж������ķ������ǣ������ֻҪ�����������ƽ������ȫ����������ʱ��Ϳ���˵����������

����һ�ַ��������10���ڵ������Ϳ�����100���ڵ����������С��10�����������100���ڵ�����
Ҫ��10000���ڵ������Ϳ���ͨ�������100���ڵ�����   ��10000���ڵ���ȥ����100���ڵ���������������Ϊ0��ʱ��Ϳ���˵���Ǹ���������


#include<stdio.h>
#include<math.h>
int judge_primenumber(int n);
int main()
{
	int n, i, k=0;
	int x, y=3;
	scanf("%d", &n);
	if(n<=4)
	{
		printf("0");
	}
	else
	{
		for(i=3; i<=n; i++)
		{
			if(judge_primenumber(i))
			{
				x = y;
				y = i;
				if(y-x == 2)
				{
					k++;
				}
			}
		}
		printf("%d", k);
	}
	return 0;
}
int judge_primenumber(int n)
{
	int i;
	for(i=2; i<=sqrt(n); i++)
	{
		if(n%i == 0)
		{
			break;
		}
	}
	if(i>sqrt(n))
	{
		return 1;
	}
	return 0;
}