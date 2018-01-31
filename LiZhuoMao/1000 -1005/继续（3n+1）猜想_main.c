#include <stdio.h>
#include <stdlib.h>
/*��Ŀ���� ��������3n+1������
  ʱ������ ��400ms
  �ڴ����� ��65536kb
  ���볤�� ��8000b
  ����     ����׿ï
  ����     ��2018.1.16 
*/ 

/*����Ҫ�� �� 
������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�
��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ������
�����n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ��
�Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ�
���ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ����������n���ܱ������е��������������ǡ�
���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡�
�����������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�
�����ʽ��ÿ�������������1��������������1�и���һ��������K(<100)����2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������
�����ʽ��ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�
*/ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct callatz{
	int data; //�洢����֤���� 
	int data_2;//�洢�ı�ǰ��ֵ 
	int record; //���λ ��Ǹ������ֵĴ��� 
};
int main(int argc, char *argv[]) 
{
	int num; //�洢����Ĵ���֤���ĸ���
	while (scanf("%d", &num) != 1 || num > 100 || num < 0) //������� ����֤���� 
	{
		puts("������һ��С��100����Ȼ��");
		while (getchar() != '\n')
			continue;
	}
	struct callatz numbers[num]; //����һ������num����������
	int i = 0, j = 0, x = 0; //ѭ������ 
	for (i = 0; i < num; i++) //���λ��ʼ�� 
		numbers[i].record = 0;
	int record_num[1000]; //�洢��3n+1�������г��ֵ��� 
	for (i = 0; i < num; i++) //����num������ �����в��� 
	{
		while (scanf("%d", &numbers[i].data) != 1 || numbers[i].data >100 || numbers[i].data <= 1)
		{
			puts("������һ������1С��100��������");
			while (getchar() != '\n')
				continue;
		}	
	}
	for (i = 0; i < num; i++) //��ȡ��ʼֵ 
	{
		numbers[i].data_2 = numbers[i].data;
	}
	for (i = 0; i < num; i++)  //��3n+1�����룬��¼���ֹ������� 
	{
		while (numbers[i].data != 1)  
		{
			if (numbers[i].data % 2 == 1)
				numbers[i].data = (3 * numbers[i].data + 1) / 2;
			else
				numbers[i].data = numbers[i].data / 2;
			record_num[j] = numbers[i].data; //��¼���ֵ��� 
			++j;
		}
	}
//	for (i = 0; i < j; i++)
//	{
//		printf("%d ", record_num[i]);
//	}
	for (i = 0; i < num; i++)
	{
		x = 0; //��ʼ��ѭ������ 
		while (x < j) //������¼���� �������ؼ��� 
		{
			if (numbers[i].data_2 == record_num[x])
				numbers[i].record++;
			++x;
		}
	}
	int get[num]; //�õ��ؼ��� 

	j = 0;
	for (i = 0; i < num; i++)
	{
		if(numbers[i].record == 0)
		{
			get[j] = numbers[i].data_2;			
			++j;
		}
	} 

		for (i = 0; i < j - 1; i++) //�Թؼ��ֽ������� 
	{
		for (x = 0; x < j - i - 1; x++)
		{
			if (get[x] < get[x + 1])
			{
				int temp = get[x];
				get[x] = get[x + 1];
				get[x + 1] = temp;
			}
		}
	}

	for (i = 0; i < j; i++)
	{
		printf("%d ", get[i]);
	}
	return 0;
}




